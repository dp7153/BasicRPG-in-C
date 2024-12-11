#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "allMyHeaders.h"

/*
trenutne ideje:
    -dodati nek del, kjer je varno - hub, shop, ogled trofej
    -healing items, inventory
    -enemy leveling: pri izdelavi enemy structa doda nek
     modifier, s katerim množi, da zmanjša frustracijo začetnikov
    -trophies: seznam že premaganih nasprotnikov
    -starter weapons, mogoče tutorial
    -savegame, ki shrani progress
*/

int main(){

    srand(time(NULL));
    splashScreen(5, 100);
    printf("\n\n\n");

    //difficulty: 0 - very easy, 1 - easy, 2 - medium, 3 - hard
    int difficulty = 0;
    int permadeath = 1;
    int baseHealth = 20;
    int modifier = 1;

    Player player1 = titleScreen(&difficulty, &permadeath, baseHealth, modifier);
    //printf("difficulty: %d\npermadeath: %d\n\n", difficulty, permadeath);
    
    /*start:
    printf("\n\n\n");

    if(difficulty == 0){
        modifier *= 5;
    }
    else if(difficulty == 1){
        modifier *= 3;
    }
    else if(difficulty == 2){
        modifier *= 1.5;
    }

    player1.health = baseHealth * modifier;*/
    
    /*Player player1 = createPlayer(baseHealth, modifier);
    player1.weapons[0] = createWeapon();*/
    
    tavern(&player1, difficulty, permadeath, baseHealth, modifier);
    //fight(&player1, difficulty);

    //struct Weapon weapon1 = createWeapon();
    //weapon1.damage = weaponDamage();
    //weapon1.condition = 1;
    //strncpy(weapon1.name, weaponName(), strlen(weaponName()));*/

    //player1.weapons[1] = createWeapon();


    if(!permadeath){
        printf("\nTry again? [y/n]\n");
        getchar();
        if(getchar() == 'y'){
            //goto start;
            player1.health = 1;
            tavern(&player1, difficulty, permadeath, baseHealth, modifier);
        }
        else{
            printf("Thanks for playing :)\n");
        }
    }

    return 0;
}