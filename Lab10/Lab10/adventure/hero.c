/*
    Filename: hero.c
    This is the implemetion of the hero functions
*/

#include"hero.h"

Hero* hero_init(char* h_name, char* h_class, int h_strength, int h_agility, int h_intelligence, int h_charisma) {
    Hero* hero = malloc(sizeof(Hero));
    hero->h_name = malloc(sizeof(char) * (strlen(h_name) + 1));
    strcpy(hero->h_name, h_name);
    hero->h_class = malloc(sizeof(char) * (strlen(h_class) + 1));
    strcpy(hero->h_class, h_class);
    hero->h_strength = (double)h_strength;
    hero->h_agility = (double)h_agility;
    hero->h_intelligence = (double)h_intelligence;
    hero->h_charisma = (double)h_charisma;

    // Figures out what the primary stat is
    // This should save time calculating it everytime we level up
    hero->h_primary = &(hero->h_charisma);
    if (h_intelligence >= *(hero->h_primary)) hero->h_primary = &(hero->h_intelligence);
    if (h_agility >= *(hero->h_primary)) hero->h_primary = &(hero->h_agility);
    if (h_strength >= *(hero->h_primary)) hero->h_primary = &(hero->h_strength);

    // New heros are always set to level 0
    hero->h_level = 0;
    
    // New heros always start alive
    hero->h_death_location = NULL;
    hero->h_alive = true;

    return hero;
}

void hero_level_up(Hero* hero) {
    hero->h_level++;
    
    // Makes sure the primary goes up by 0.35 (0.1 + 0.25)
    *(hero->h_primary) += 0.1;

    // Everything goes up by 0.25 points
    hero->h_strength += 0.25;
    hero->h_agility += 0.25;
    hero->h_intelligence += 0.25;
    hero->h_charisma += 0.25;
}

bool hero_destroy(Hero* hero) {
    if (hero == NULL) return true;
    free(hero->h_name);
    free(hero->h_class);

    free(hero);
    hero = NULL;
    return true;
}
