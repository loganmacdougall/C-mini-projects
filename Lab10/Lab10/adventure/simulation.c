/*
    Filename: simulation.c
    This is the implemetion of the simulation functions
*/

#include"simulation.h"

int main(int argc, char* argv[]) {
    // Thread count is 1 or whatever is specified in the program arguments
    int threadCount = 1;
    if (argc >= 2) threadCount = atoi(argv[1]);

    World* world = world_create("heroes.lot", "locations.lot");
  
    for (enum attribute att = 0; att < 5; att++) {
	World* cpyWorld = world_copy(world);
	run_path(cpyWorld, att, threadCount);
	world_destroy(cpyWorld);
    }

    world_destroy(world);
}

void run_path(World* world, enum attribute order, int threadCount) { 
    // Setup up the sorted list of locations and the queue of heroes
    ArrayList* path = alist_initialize(200, sizeof(Location*), "Location*");
    Heap* sorted_locations = heap_initialize(sizeof(Location*), "Location*", location_compare, NULL);
    Queue* heroes = queue_initialize(sizeof(Hero*), "Hero*"); 

    pthread_t threads[threadCount];

    int locLen  = world->locations->size;
    int heroLen = world->heroes->size;

    for(int i = 0; i < locLen; i++) {
	Location** tmp_location = alist_get(world->locations, i);
	(*tmp_location)->order = order;
	heap_insert(sorted_locations, tmp_location);
	free(tmp_location);
    }
    for(int i = 0; i < locLen; i++) {
	Location** tmp_location = heap_remove(sorted_locations);
	alist_add(path, tmp_location);
	free(tmp_location);
    }
    heap_destroy(sorted_locations);
    for(int i = 0; i < heroLen; i++) {
	Hero** tmp_hero = alist_get(world->heroes, i);
	queue_enqueue(heroes, tmp_hero);
	free(tmp_hero);
    }

    printf("running the %s path\n", attributeToString(order));

    //Start the timer
    struct timeval startTime, endTime;
    gettimeofday(&startTime, NULL);

    // Create the first set of threads
    Args args[threadCount];
    for(int i = 0; i < threadCount; i++) {	
	args[i].hero = queue_dequeue(heroes);
	args[i].path = path;
	pthread_create(&threads[i], NULL, adventure, &args[i]);
	print_progress(heroLen - queue_size(heroes), heroLen);
    }
 
    for(int i = 0; queue_size(heroes) > 0; i = (i+1) % threadCount) {
	if (args[i].is_complete) {
	    pthread_join(threads[i], NULL);
	    free(args[i].hero);
	    args[i].hero = queue_dequeue(heroes);
	    pthread_create(&threads[i], NULL, adventure, &args[i]);
	    print_progress(heroLen - queue_size(heroes), heroLen);
	}
    }

    //Go to the next line after the progress bar
    printf("\n");

    for (int i = 0; i < threadCount; i++) {
	pthread_join(threads[i], NULL);
	free(args[i].hero);
    }

    gettimeofday(&endTime, NULL);
    long timeTaken = (endTime.tv_sec - startTime.tv_sec)*1000000 + (endTime.tv_usec - startTime.tv_usec);

    printf("Time elapsed: %ld microseconds\n\n", timeTaken);
    queue_destroy(heroes);
    alist_destroy(path);

    print_results(world, order);
}

void* adventure(void* args_void) {
	Args* args = (Args*)args_void;

        args->is_complete = false;
	Hero* hero = *args->hero;
	ArrayList* path = args->path;	

	int pathSize = path->size;
	bool success;
	Location* location;
	Location** location_pointer;
	for (int i = 0; i < pathSize; i++) {
	    location_pointer = alist_get(path, i);
	    location = *location_pointer;
	    
	    //Wait for locaiton to be available
	    sem_wait(&location->l_lock);
	    success = challenge_location(hero, location);

	    //Location can be entered again
	    sem_post(&location->l_lock);

	    //If hero died
	    if (!success) {
		args->is_complete = true;
		free(location_pointer);
		return NULL;
	    }
	    free(location_pointer);
	}
	args->is_complete = true;
	return NULL;
}

bool challenge_location(Hero* hero, Location* location) {

    bool result = challenge_success(hero, location);

    // If hero loses the challenge...
    if (!result) {
	hero->h_alive = false;
	hero->h_death_location = location;
	
	Hero** tmp_hero_loc = malloc(sizeof(Hero*));
	*tmp_hero_loc = hero;
	alist_add(location->l_dead_heroes, tmp_hero_loc);
	free(tmp_hero_loc);
    // Else if the hero wins
    } else {
	hero_level_up(hero);
    }
    
    return result;
}

bool challenge_success(Hero* hero, Location* location) {
    // The 4 stats challenges will be called sc1-4
    double sc1 = hero->h_strength - (double)location->l_power;
    double sc2 = hero->h_agility - (double)location->l_subtlety;
    double sc3 = hero->h_intelligence - (double)location->l_strategy;
    double sc4 = hero->h_charisma - (double)location->l_charm;

    return (sc1 >= 0) || (sc2 >= 0) || (sc3 >= 0) || (sc4 >= 0);
}

void print_progress(int value, int maxValue) {
    int length = 30;
    char* prefix = "Heroes run/ning:";

    int divideAmount = maxValue/length;

    printf("\r%s ", prefix);
    
    // Number of chars which will actually be written to the screen
    int screenValue = value/divideAmount;
    int screenMaxValue = (maxValue/divideAmount) - screenValue;
    
    for (int i = 0; i < screenValue; i++) printf("#");
    for (int i = 0; i < screenMaxValue; i++) printf("-");

    double progress = 100 * (double)value/(double)maxValue;

    printf(" %.2lf%% ", progress);
    // Not printing an enter space so we need to fflush to print to screen
    fflush(stdout);

    return;
}

void print_results(World* world, enum attribute order) {

    ArrayList* heroPointers = world->heroes;
    
    char* alive_out_name = malloc(sizeof(char) * 25);
    char* dead_out_name = malloc(sizeof(char) * 24);

    sprintf(alive_out_name,"%s_alive",attributeToString(order));
    sprintf(dead_out_name,"%s_dead",attributeToString(order));

    FILE* alive_out = fopen(alive_out_name, "w");
    FILE* dead_out  = fopen(dead_out_name, "w");

    free(alive_out_name);
    free(dead_out_name);

    Hero** hero_pointer_tmp;
    Hero* hero_tmp;

    for (int i = 0; i < heroPointers->size; i++) {
	hero_pointer_tmp = alist_get(heroPointers, i);
	hero_tmp = *hero_pointer_tmp;
       
	if (hero_tmp->h_alive) {
	    fprintf(alive_out, "%s %d %d %d %d\n",
	    hero_tmp->h_name,
	    (int)hero_tmp->h_strength,
	    (int)hero_tmp->h_agility,
	    (int)hero_tmp->h_intelligence,
	    (int)hero_tmp->h_charisma);
	} else {
	    fprintf(dead_out, "%s %d %d %d %d %d %s\n",
	    hero_tmp->h_name,
	    (int)hero_tmp->h_strength,
	    (int)hero_tmp->h_agility,
	    (int)hero_tmp->h_intelligence,
	    (int)hero_tmp->h_charisma,
	    hero_tmp->h_level,
	    hero_tmp->h_death_location->l_name);
	}
	free(hero_pointer_tmp);
    }

    fclose(alive_out);
    fclose(dead_out);
}
