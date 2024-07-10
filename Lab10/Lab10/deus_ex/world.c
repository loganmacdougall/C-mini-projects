/*
    Filename: world.c
    This is the implemetion of the world functions
*/

#include"world.h"

World* world_create(char* heroes_filename, char* locations_filename) {
    if (heroes_filename == NULL || locations_filename == NULL) return NULL;
    World* world = malloc(sizeof(World));
    world->heroes = alist_initialize(300,sizeof(Hero*),"Hero*");
    world->locations = alist_initialize(200,sizeof(Location*),"Location*");

    size_t bufferSize = 0;

    // Read through all the heros in the heroes.lot file and put them into the heroes ArrayList

    // The arraysizes are made very large only for reading to the file
    // The the hero object, they are stored with the size of the string
    char* h_name = NULL;
    char* h_class = NULL;

    int h_strength;
    int h_agility;
    int h_intelligence;
    int h_charisma;

    FILE* h_in = fopen(heroes_filename, "r");
    while(getline(&h_name, &bufferSize, h_in) != EOF) {
        bufferSize = 0;
        getline(&h_class, &bufferSize, h_in);
        bufferSize = 0;
        fscanf(h_in, "%d, %d, %d, %d\n", &h_strength, &h_agility, &h_intelligence, &h_charisma);

        h_name[strlen(h_name) - 1] = '\0';
        h_class[strlen(h_class) - 1] = '\0';

        Hero** tmp_hero_pointer = malloc(sizeof(Hero*));
        *tmp_hero_pointer = hero_init(h_name, h_class, h_strength, h_agility, h_intelligence, h_charisma);
        alist_add(world->heroes, tmp_hero_pointer);
        free(tmp_hero_pointer);

        free(h_name);
        h_name = NULL;
        free(h_class);
	h_class = NULL;
    }
    free(h_name);
    fclose(h_in);

    // Read through all the locations in the locations.lot file and put them into the location
    char* l_name = NULL;

    int l_level;
    int l_power;
    int l_subtlety;
    int l_strategy;
    int l_charm;

    FILE* l_in = fopen(locations_filename, "r");
    while(getline(&l_name, &bufferSize, l_in) != EOF) {
        bufferSize = 0;
        fscanf(l_in, "%d, %d, %d, %d, %d\n", &l_level, &l_power, &l_subtlety, &l_strategy, &l_charm);

        l_name[strlen(l_name) - 1] = '\0';

        Location** tmp_loc_pointer = malloc(sizeof(Location*));
        *tmp_loc_pointer = location_init(l_name, l_level, l_power, l_subtlety, l_strategy, l_charm);
        alist_add(world->locations, tmp_loc_pointer);
        free(tmp_loc_pointer);

        free(l_name);
        l_name = NULL;
    }
    free(l_name);
    fclose(l_in);

    return world;
}

World* world_copy_for_attr(World* world, enum attribute order) {
    if (world == NULL) return NULL;
    World* cpy = malloc(sizeof(World));
    cpy->heroes = alist_initialize(100,sizeof(Hero*),"Hero*");
    cpy->locations = alist_initialize(200,sizeof(Location*),"Location*");

    int heroesLen = world->heroes->size;
    int locationsLen = world->locations->size;

    // Copy all the heros and locations in world and put them into the heroes and locations ArrayList in cpy
    // Made sure that no memory-leaks are possible with this extended way of copying variables

    //OG is the orginal Hero in world->heroes at index i
    //CP is the copy of the OG
    
    for(int i = 0; i < heroesLen; i++) {
	Hero** OG_hero_pointer = alist_get(world->heroes, i);	// Get pointer to OG
	Hero* CP_hero = hero_init(				// Create space for CP
	    (*OG_hero_pointer)->h_name,
	    (*OG_hero_pointer)->h_class,
	    (*OG_hero_pointer)->h_strength,
	    (*OG_hero_pointer)->h_agility,
	    (*OG_hero_pointer)->h_intelligence,
	    (*OG_hero_pointer)->h_charisma
	);	
	free(OG_hero_pointer);					// Remove OG pointer (already copied to CP)
	// Takes adventage of how the Hero struct is laid out and the order
	// of the enum to check if the address of the primary attribute
	// matches the address of the path order were using
	if (CP_hero->h_primary != &(CP_hero->h_strength) + order - 1) {
	    hero_destroy(CP_hero);
	    continue;
	}
	Hero** CP_hero_pointer = malloc(sizeof(Hero*));		// Create space for CP pointer
	*CP_hero_pointer = CP_hero;				// Set CP pointer to CP
	alist_add(cpy->heroes, CP_hero_pointer);		// Add CP pointer to list
	free(CP_hero_pointer);					// Remove CP pointer (already copied in list)
    }

    // Does the same thing as the above loop but for world->locations
    // and doesn't do any filtering
    for(int i = 0; i < locationsLen; i++) {
	Location** OG_location_pointer = alist_get(world->locations, i);
	Location* CP_location = location_init(
	    (*OG_location_pointer)->l_name,
	    (*OG_location_pointer)->l_level,
	    (*OG_location_pointer)->l_power,
	    (*OG_location_pointer)->l_subtlety,
	    (*OG_location_pointer)->l_strategy,
	    (*OG_location_pointer)->l_charm
	);
	free(OG_location_pointer);
	Location** CP_location_pointer = malloc(sizeof(Location*));
	*CP_location_pointer = CP_location;
	alist_add(cpy->locations, CP_location_pointer);
	free(CP_location_pointer);
    }

    // We then sort the Locations using a heap
    Heap* sorted_locations = heap_initialize(sizeof(Location*), "Location*", location_compare, NULL);
    int locLen  = world->locations->size;

    // Pop all the Locaitons from the ArrayList in cpy into the Heap
    for(int i = 0; i < locLen; i++) {
        Location** tmp_location = alist_remove_end(cpy->locations);
        (*tmp_location)->order = order;
        heap_insert(sorted_locations, tmp_location);
        free(tmp_location);
    }
    // Then pop all the Locations in the Heap and push them onto the ArrayList in cpy
    for(int i = 0; i < locLen; i++) {
        Location** tmp_location = heap_remove(sorted_locations);
        alist_add(cpy->locations, tmp_location);
        free(tmp_location);
    }

    heap_destroy(sorted_locations);

    //Returns world with sorted paths and filtered heroes
    return cpy;
    
}

bool world_destroy(World* world) {
    if (world == NULL) return true;

    // The alist_destroy function doesn't properly destroy
    // pointers to pointers to buffers, so we manually have to free the buffers.
    // Then the arraylist can take care of the pointers
    int heroesLen = world->heroes->size;
    int locationsLen = world->locations->size;

    for (int i = 0; i < heroesLen; i++) {
        Hero** tmp_hero_pointer = alist_get(world->heroes, i);
        Hero* tmp_hero = *tmp_hero_pointer;
        hero_destroy(tmp_hero);
        free(tmp_hero_pointer);
    }
    alist_destroy(world->heroes);

    for(int i = 0; i < locationsLen; i++) {
        Location** tmp_location_pointer = alist_get(world->locations, i);
        Location* tmp_location = *tmp_location_pointer;
        location_destroy(tmp_location);
        free(tmp_location_pointer);
    }
    alist_destroy(world->locations);

    free(world);
    world = NULL;

    return true;
}
