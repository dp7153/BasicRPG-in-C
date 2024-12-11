#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "allMyHeaders.h"

//napad, pošljemo kazalce orožja in sovraga
void attack(Weapon *weapon, Enemy *enemy, int *coin){
    //nasprotnikovo življenje se zmanjša za vrednost napada orožja
    enemy->health -= weapon->damage;
    printf("You attacked and dealt %d damage\n\n", weapon->damage);
    if(enemy->health <= 0){
        enemy->health = 0;
        printf("%s the %s died\n\n", enemy->name, enemy->race);
        int received = 20;
        *coin += received;
        printf("You received %d coins\n", received);
        return;
    }
    //kako se orožje poškoduje določimo s rand, max 5%
    weapon->condition -= rand() % 5;
    if(weapon->condition <= 0 && strncmp(weapon->name, "Fists", 5) != 0){
        weapon->condition = 0;
        weapon->damage = 0;
        printf("Your weapon is broken and doesn't do any damage\n\n");
    }
    //printf("%d\n", enemy->health);
}

void heal(int* playerHealth){
    int amountHealed = rand() % 20;
    while(amountHealed == 0){
        amountHealed = rand() % 20;
    }
    *playerHealth += amountHealed;
    printf("You were healed for %d HP\n\n", amountHealed);
}

int flee(int* playerHealth){
    int chance = 50 - *playerHealth;
    int success = rand() % 100;
    if(chance > success){
        printf("You escaped successfully\n");
        return 1;
    }
    printf("The escape was not a success\n\n");
    return 0;
}

int addWeapon(Player *player1, int inventorySize, Weapon weaponNew){
    //Weapon weaponNew = createWeapon();
    printf("New weapon:\n%s\n%d attack damage\n%d%% durability\n", weaponNew.name, weaponNew.damage, weaponNew.condition);
    
    int prostoMesto = -1;
    for(int i = 0; i < player1->inventorySize; i++){
        if(player1->weapons[i].name == NULL || player1->weapons[i].damage == 0){
            prostoMesto = i;
            break;
        }
        //printf("%d\n", i);
    }
    if(prostoMesto == -1){
        printf("You have no space for a new weapon. Discard an old one?[y/n]\n");
    }
    else{
        printf("Add the new weapon to the inventory?[y/n]\n");
    }
    //printf("Do you want to take this new weapon and discard the old one? [y/n]\n");
    char choice = getchar();
    if(choice = 10){
        choice = getchar();
    }
    //printf("you have chosen: %c\n", choice);

    

    while(choice != 'y' && choice != 'n'){
        printf("Input not valid, please respond affirmative or decline the new weapon [y/n]\n");
        getchar();
        choice = getc(stdin);
    }

    if(choice == 'y'){
        if(prostoMesto != -1){
            player1->weapons[prostoMesto] = weaponNew;
            return 1;
        }
        else{
            printf("Which one do you want to replace?\n");
            for(int i = 0; i < inventorySize; i++){
                printf("[%d] - %s: damage: %d, condition: %d%%\n", i+1, player1->weapons[i].name, player1->weapons[i].damage, player1->weapons[i].condition);
            }
            printf("Or cancel? [0]\n");
            
            //getchar();
            choice = getchar();
            if(choice == 10){
                choice = getchar();
            }
            if(choice == '0'){
                printf("\nYou decided it was better to keep the old weapon\n\n");
                return 0;
            }
            player1->weapons[choice - '0' - 1] = weaponNew;
            //printf("LOL %s\nLOL %s", player1->weapons[choice - '0'].name, weaponNew.name);
            return 1;
        }
        /*weapon1->condition = weaponNew.condition;
        weapon1->damage = weaponNew.damage;
        weapon1->name = weaponNew.name;*/

        //printf("\nNew Weapon: %s with %d attack damage and %d%% durability\n\n", weapon1->name, weapon1->damage, weapon1->condition);
    }
    else if(choice == 'n'){
        printf("\nYou decided against adding new weapons\n\n");
        return 0;
    }
    return 0;
}

void printInventory(Player player1){
    printf("%s: %dHP\n", player1.name, player1.health);
    printf("Coins: %d\n", player1.coins);
    for(int i = 0; i < player1.inventorySize; i++){
        if(player1.weapons[i].damage < 1 || player1.weapons[i].condition < 1){
            //*inventorySize = i;
            break;
        }
        printf("[%d] - %s: damage: %d, condition: %d%%\n", i+1, player1.weapons[i].name, player1.weapons[i].damage, player1.weapons[i].condition);
    }//printf("Or cancel? [0]\n");
}

int changeWeapon(Player *player1, int *inventorySize){
    /*printf("Inventory\n");
    for(int i = 0; i < *inventorySize; i++){
        if(player1->weapons[i].damage < 1 || player1->weapons[i].condition < 1){
            *inventorySize = i;
            break;
        }
        printf("[%d] - %s: damage: %d, condition: %d%%\n", i+1, player1->weapons[i].name, player1->weapons[i].damage, player1->weapons[i].condition);
    }//printf("Or cancel? [0]\n");*/

    printInventory(*player1);
    
    getchar();
    int choice = getchar() - '0' - 1;
    printf("\n");

    if(choice > 0 && choice < *inventorySize){
        /*struct Weapon temp = player1->weapons[0];
        player1->weapons[0] = player1->weapons[choice];
        player1->weapons[choice] = temp;*/
        return choice;
    }
    return 0;
}