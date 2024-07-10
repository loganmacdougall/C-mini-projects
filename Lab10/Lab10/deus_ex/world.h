/*
    Filename: world.h
    This is the header file for world.c
*/

#ifndef __HEADER_WORLD
#define __HEADER_WORLD
#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"lib/array_list.h"
#include"lib/heap.h"
#include"location.h"
#include"hero.h"

// Stores all the hero and location data
typedef struct _world_data {
    ArrayList* heroes;
    ArrayList* locations;
} World;

// Gets recieves both lot files, reads them, stores them
// in a World struct and return the world struct.
World* world_create(char* heroes_filename, char* locations_filename);

// Returns a partial-deep copy of the world so you
// don't have to re-read a file everytime
// It will also sort the paths the paths and return
// only the heroes optimal for that path
// Note: This assumes that the data is un-altered from the file
// Aswell, the char* variables are shallow copied
World* world_copy_for_attr(World* world, enum attribute order);

// Safely destorys the world and everythin inside of it.
// This is so when we remove elements from queues or other data structures
// we won't lose any of that data until it's freed by this function
bool world_destroy(World* world);

#endif
