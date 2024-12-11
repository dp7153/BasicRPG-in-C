#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weapons.h"
//#include "allMyHeaders.h"


typedef struct Enemy{
    char* race;
    char* name;
    int health;
    Weapon weapon;
} Enemy;

char* race(){
    
    char* race[] = {"Orc", "Goblin", "Human", "Dragon", "Hobbit", "Elf", "Dwarf", NULL};
    int raceLength = arrayLength(race);
    
    //srand(time(NULL));

    int raceChosen = rand() % raceLength;
    char *decidedRace = (char*)malloc((strlen(race[raceChosen]) + 1) * sizeof(char));
    strncpy(decidedRace, race[raceChosen], strlen(race[raceChosen]));
    //printf("race length: %ld\n", strlen(race[raceChosen]));
    decidedRace[strlen(race[raceChosen])] = '\0';
    return decidedRace;
}

char* nameHumanoid(){
    char* name[] = {"Steve", "John", "Jack", "Ariel", "Elise", "Franklin", "Mike", NULL};
    int nameLength = arrayLength(name);

    //srand(time(NULL));

    int nameChosen = rand() % nameLength;
    char *decidedName = (char*)malloc((strlen(name[nameChosen]) + 1) * sizeof(char));
    strncpy(decidedName, name[nameChosen], strlen(name[nameChosen]));
    //printf("name length: %ld\n", strlen(name[nameChosen]));
    decidedName[strlen(name[nameChosen])] = '\0';
    return decidedName;
}

Enemy createEnemy(){
    Enemy enemy1;
    //strncpy(enemy1.race, race(), strlen(race()));
    enemy1.race = race();
    //strncpy(enemy1.name, nameHumanoid(), strlen(nameHumanoid()));
    enemy1.name = nameHumanoid();
    enemy1.health = weaponCondition();
    if(enemy1.health == 0){
        enemy1.health = weaponCondition();
    }
    enemy1.weapon = createWeapon();
    if(enemy1.weapon.damage == 0){
        enemy1.weapon = createWeapon();
    }

    return enemy1;
}

void enemyAttack(Enemy *enemy, int* playerHealth){
    *playerHealth -= enemy->weapon.damage;
    if(*playerHealth <= 0){
        *playerHealth = 0;
        //printf("You died\n");
    }
}