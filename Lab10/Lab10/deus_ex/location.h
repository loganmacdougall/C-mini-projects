/*
    Filename: location.h
    This is the header file for location.h
*/

#ifndef __HEADER_LOCATION
#define __HEADER_LOCATION

#include<string.h>
#include<stdlib.h>
#include<semaphore.h>
#include"lib/array_list.h"

enum attribute {level, power, subtlety, strategy, charm};

//definition of a location
typedef struct _Location {
    ArrayList* l_dead_heroes;
    char* l_name;
    int l_level;
    int l_power;
    int l_subtlety;
    int l_strategy;
    int l_charm;
    enum attribute order;
    sem_t l_lock;
} Location;

// Because our "Hero" struct has a "Location" struct inside of it,
// we need to define Location before including hero.h
#include"hero.h"

// Initializes a locaiton and returns it
Location* location_init(char* l_name, int l_level, int l_power, int l_subtlety, int l_strategy, int l_charm);

// Compares 2 locations by which one the hero should come to first
int location_compare(void* a, void* b);

char* attributeToString(enum attribute att);

// Safely destorys the location.
bool location_destroy(Location* location);

#endif
