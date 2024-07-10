/*
    Filename: location.c
    This is the implemetion of the location functions
*/

#include"location.h"

Location* location_init(char* l_name, int l_level, int l_power, int l_subtlety, int l_strategy, int l_charm) {
    Location* location = malloc(sizeof(Location));
    location->l_name = malloc(sizeof(char) * (strlen(l_name) + 1));
    strcpy(location->l_name, l_name);
    location->l_level = l_level;
    location->l_power = l_power;
    location->l_subtlety = l_subtlety;
    location->l_strategy = l_strategy;
    location->l_charm = l_charm;

    // Default values
    location->l_dead_heroes = alist_initialize(2,sizeof(Hero*),"Hero*");

    sem_init(&location->l_lock, 0, 1);

    return location;
}

int location_compare(void* a, void* b) {
    Location* locA = *(Location**)a;
    Location* locB = *(Location**)b;

    int result, attA, attB;
    // sorted by the order stored in both LocA and B
    attA = *(&locA->l_level + locA->order);
    attB = *(&locB->l_level + locA->order);
    return  attB - attA;
}

char* attributeToString(enum attribute att) {
    switch(att) {
	case level:
	    return "level";
	case power:
	    return "power";
	case subtlety:
	    return "subtlety";
	case strategy:
	    return "startegy";
	case charm:
	    return "charm";
	default:
	    return NULL;
    }
}

bool location_destroy(Location* location) {
    if (location == NULL) return true;
    alist_destroy(location->l_dead_heroes);
    free(location->l_name);
    
    free(location);
    location = NULL;
    return true;
}
