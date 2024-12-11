#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Weapon{
    int damage;
    int condition;
    char* name;
} Weapon;

int arrayLength(char** array){
    char **skokec = array;
    int stevec = 0;
    while(*skokec != NULL){
        stevec++;
        skokec++;
        //printf("%d\n", stevec);
    }
    return stevec;
}

char* weaponName(){
    char* type[] = {"Sword", "Axe", "Javelin", "Pike", "Spear", "Bow", "Mace", NULL};
    char* suffix[] = {"Truth", "Power", "Desire", "Destiny", "Strength", "Reluctance", NULL};

    int typeLength = arrayLength(type);//6;
    //printf("%d\n", typeLength);
    int suffixLength = arrayLength(suffix);//6;
    //printf("%d\n", suffixLength);

    //srand(time(NULL));

    int randomType = random() % typeLength;
    int randomSuffix = random() % suffixLength;

    int fullWeaponLength = strlen(type[randomType]) + strlen(suffix[randomSuffix]) + strlen(" of ");

    char* fullWeaponName = (char*) calloc(fullWeaponLength, sizeof(char));
    strncpy(fullWeaponName, type[randomType], strlen(type[randomType]));
    strncat(fullWeaponName, " of ", 4);
    strncat(fullWeaponName, suffix[randomSuffix], strlen(suffix[randomSuffix]));

    //printf("%d %ld\n", fullWeaponLength, strlen(fullWeaponName));

    return fullWeaponName;
}  

int weaponDamage(){
    //srand(time(NULL));
    int damage = rand() % 20;
    while(damage == 0){
        damage = rand() % 20;
    }
    return damage;
}

int weaponCondition(){
    //srand(time(NULL));
    int condition = rand() % 100;
    while(condition == 0){
        condition = rand() % 100;
    }
    return condition;
}

Weapon createWeapon(){
    Weapon weapon1;
    weapon1.damage = weaponDamage();
    weapon1.condition = weaponCondition();
    //strncpy(weapon1.name, weaponName(), strlen(weaponName()));
    weapon1.name = weaponName();

    return weapon1;
}