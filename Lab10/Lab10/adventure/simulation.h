/*
    Filename: simulation.h
    This is the header file for simulation.c
*/

#ifndef __HEADER_SIMULATION
#define __HEADER_SIMULATION

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/time.h>
#include"lib/array_list.h"
#include"lib/queue.h"
#include"lib/heap.h"
#include"location.h"
#include"hero.h"
#include"world.h"

// Stores all the arguments required for the threads to run
typedef struct _sim_args {
    Hero** hero;
    ArrayList* path;
    bool is_complete;
} Args;

void run_path(World* world, enum attribute order, int threadCount);

// This will be the thread function that will take the hero
// along it's entire adventure
void* adventure(void* args_void);

// Has a hero challenge a location
// Return the result of the hero challenging the location
bool challenge_location(Hero* hero, Location* location);

// Returns if a hero would be successful at challenging a location
bool challenge_success(Hero* hero, Location* location);

// This will nicely display how many heroes are left in the queue
void print_progress(int value, int maxValue);

// Will print the results to the 2 files
void print_results(World* world, enum attribute order);

#endif
