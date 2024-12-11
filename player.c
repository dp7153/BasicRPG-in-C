#include <stdio.h>
#include <stdlib.h>
#include "weapons.h"

typedef struct Player{
    char* name;
    int coins;
    int health;
    int currentWeapon;
    int inventorySize;
    //Inventory inventory[];
    struct Weapon weapons[5];
} Player;

Player createPlayer(int baseHealth, int modifier){
    Player player1;

    /*printf("Please enter your player name\n");
    char temp[1000];
    
    char c = getchar();
    while(c == 10){
        c = getchar();
    }
    int dolzinaImena = 0;
    temp[0] = c;
    while(c != '\n'){
        c = getchar();
        dolzinaImena++;
        temp[dolzinaImena] = c;
    }printf("\n");
    char *ime = (char*) malloc((dolzinaImena + 1) * sizeof(char));
    for(int i = 0; i < dolzinaImena; i++){
        ime[i] = temp[i];
    }
    ime[dolzinaImena + 1] = '\0';

    player1.name = ime;*/

    player1.name = "temp";

    //printf("%s\n", player1.name);

    player1.coins = 0;
    player1.health = baseHealth * modifier;
    player1.currentWeapon = 0;
    player1.inventorySize = 5;
    player1.weapons[player1.currentWeapon].name = "Fists";
    player1.weapons[player1.currentWeapon].damage = 1;
    player1.weapons[player1.currentWeapon].condition = 100;

    for(int i = 1; i < player1.inventorySize; i++){
        player1.weapons[i].damage = 0;
    }
    //printf("%s: %d, %d%%\n", player1.weapons[0].name, player1.weapons[0].damage, player1.weapons[0].condition);

    return player1;
}