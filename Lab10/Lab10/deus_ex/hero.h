/*
    Filename: hero.h
    This is the header file for hero.c
*/

#ifndef __HEADER_HERO
#define __HEADER_HERO

#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include"location.h"

//definition of a hero
typedef struct _Hero {
    Location* h_death_location;
    double* h_primary;
    char* h_name;
    char* h_class;
    double h_strength;
    double h_agility;
    double h_intelligence;
    double h_charisma;
    int h_level;

    bool h_alive;
} Hero;

// Initializes a hero and returns it
Hero* hero_init(char* h_name, char* h_class, int h_strength, int h_agility, int h_intelligence, int h_charisma);

// Levels up the hero and increases all their stats
void hero_level_up(Hero* hero);

// Safely destorys the hero.
bool hero_destroy(Hero* hero);

#endif
