#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allMyHeaders.h"

void fight(Player *player1, int difficulty, int permadeath){
    
    Enemy enemy1 = createEnemy();
    
    int currentWeapon = player1->currentWeapon;
    //int inventorySize = player1.inventorySize;

    printf("%s\n", player1->name);
    printf("Your health: %d\n", player1->health);
    printf("Your weapon:\n%s: %d Attack Damage\n", player1->weapons[currentWeapon].name, player1->weapons[currentWeapon].damage);
    printf("Weapon Condition: %d%%\n\n", player1->weapons[currentWeapon].condition);

    printf("%s the %s\n", enemy1.name, enemy1.race);
    printf("Health: %d\n", enemy1.health);
    printf("Wielding: %s, damage: %d\n", enemy1.weapon.name, enemy1.weapon.damage);

    int countEnemyTurns = 0;
    int damageTaken = 0;
    while(enemy1.health > 0){
        int turn = rand() % 2;  //kdo je na vrsti: ti ali sovrag
        if(turn == 0){          //tu je na vrsti sovrag
            countEnemyTurns++;
            enemyAttack(&enemy1, &player1->health);
            damageTaken = 1;
            if(difficulty == 3 || (difficulty == 2 && countEnemyTurns < 5) || (difficulty == 1 && countEnemyTurns < 3)){
                continue;
            }
        }
        //ta del šteje kolikokrat je bil napad uspešen
        if(damageTaken == 1){
            if(countEnemyTurns > 1){
                printf("\nEnemy turn\n");
                printf("%s attacked %d times dealing %d damage\n", enemy1.name, countEnemyTurns, countEnemyTurns * enemy1.weapon.damage);
            }
            else{
                printf("\nEnemy turn\n");
                printf("%s deals %d damage\n", enemy1.name, enemy1.weapon.damage);
            }
            if(player1->health == 0){
                if(permadeath == 1){
                    printf("You died\n");
                    exit(0);
                }
                printf("You are gravely injured. Fighting is not advisable\n");
                player1->health = 1;
                break;
            }
            printf("Your health: %d\n", player1->health);
            damageTaken = 0;
            countEnemyTurns = 0;
        }

        printf("\nWhat do you do?\n[1]Attack\n[2]Heal\n[3]Change Weapon\n[4]Flee\n");
        int action;
        scanf("%d", &action);
        printf("\n");

        if(action == 1){
            attack(&player1->weapons[currentWeapon], &enemy1, &player1->coins);
        }
        else if(action == 2){
            heal(&player1->health);
        }
        else if(action == 3){
            currentWeapon = changeWeapon(player1, &player1->inventorySize);
            player1->currentWeapon = currentWeapon;
            //printf("%d\n", inventorySize);
        }
        else if(action == 4){
            int c = flee(&player1->health);
            if(c == 1){
                break;
            }
        }

        if(/*weapon1.condition > 0 && */enemy1.health > 0){
            printf("%s\n", player1->name);
            printf("Your health: %d\n", player1->health);
            printf("Your weapon:\n%s: %d Attack Damage\n", player1->weapons[currentWeapon].name, player1->weapons[currentWeapon].damage);
            printf("Weapon Condition: %d%%\n\n", player1->weapons[currentWeapon].condition);

            printf("%s the %s\n", enemy1.name, enemy1.race);
            printf("Health: %d\n", enemy1.health);
            printf("Wielding: %s, damage: %d\n", enemy1.weapon.name, enemy1.weapon.damage);
            //printf("Your health: %d\n%s's health: %d\nWeapon Condition: %d%%\n\n", health, enemy1.name, enemy1.health, weapon1.condition);
        }
        //printf("\n\n\n");
    }
}

void tavern(Player *player1, int difficulty, int permadeath, int baseHealth, int modifier);

void shop(Player *player1){
    Weapon weapon1 = createWeapon();
    weapon1.condition = 100;
    int price1 = (rand() % 10) * weapon1.damage;
    Weapon weapon2 = createWeapon();
    weapon2.condition = 100;
    int price2 = (rand() % 10) * weapon2.damage;
    Weapon weapon3 = createWeapon();
    weapon3.condition = 100;
    int price3 = (rand() % 10) * weapon3.damage;
    Weapon weapon4 = createWeapon();
    weapon4.condition = 100;
    int price4 = (rand() % 10) * weapon4.damage;

    printf("Your Coin: %d\n", player1->coins);

    printf("[1] %s - Attack Damage: %d  -> price: %d\n", weapon1.name, weapon1.damage, price1);
    printf("[2] %s - Attack Damage: %d  -> price: %d\n", weapon2.name, weapon2.damage, price2);
    printf("[3] %s - Attack Damage: %d  -> price: %d\n", weapon3.name, weapon3.damage, price3);
    printf("[4] %s - Attack Damage: %d  -> price: %d\n", weapon4.name, weapon4.damage, price4);
    printf("[0] back\n");

    char c = getchar() - '0';
    //printf("%d\n", c);

    if(c == 0){
        //printf("\n");
        //tavern(player1);
        return;
    }
    else if(c == 1){
        if(player1->coins >= price1){
            int purchased = addWeapon(player1, player1->inventorySize, weapon1);
            if(purchased == 1)
                player1->coins -= price1;
        }
        else{
            printf("You don't have enough money\n");
        }
    }
    else if(c == 2){
        if(player1->coins >= price2){
            int purchased = addWeapon(player1, player1->inventorySize, weapon2);
            if(purchased == 1)
                player1->coins -= price2;
        }
        else{
            printf("You don't have enough money\n");
        }
    }
    else if(c == 3){
        if(player1->coins >= price3){
            int purchased = addWeapon(player1, player1->inventorySize, weapon3);
            if(purchased == 1)
                player1->coins -= price3;
        }
        else{
            printf("You don't have enough money\n");
        }
    }
    else if(c == 4){
        if(player1->coins >= price4){
            int purchased = addWeapon(player1, player1->inventorySize, weapon4);
            if(purchased == 1)
                player1->coins -= price4;
        }
        else{
            printf("You don't have enough money\n");
        }
    }
}

void popraviString(char *niz, int dolzina){
    for(int i = 0; i < dolzina; i++){
        if(niz[i] == '\n'){
            niz[i] = '\0';
        }
    }
}

void tavern(Player *player1, int difficulty, int permadeath, int baseHealth, int modifier){
    char *commands[] = {"help", "shop", "fight", "inventory", "save", "title", "quit", NULL};
    int commandsLength = arrayLength(commands);
    char preglednik = 0;

    printf("\nThe place is busy, where to go? (help for list of places)\n");
    char *akcija = (char*) malloc(30 * sizeof(char));
    fgets(akcija, 30, stdin);
    popraviString(akcija, 30);
    if(strncmp(akcija, "", 30) == 0){
        fgets(akcija, 30, stdin);
    }
    popraviString(akcija, 30);
    
    printf("\n");
    if(strncmp(akcija, "shop", 5) == 0){
        shop(player1);
        preglednik = 1;
        //printf("LOL\n");
    }
    if(strncmp(akcija, "quit", 5) == 0){
        exit(0);
    }
    if(strncmp(akcija, "help", 5) == 0){
        for(int i = 0; i < commandsLength; i++){
            printf("%s\n", commands[i]);
        }printf("\n");
        preglednik = 1;
    }
    if(strncmp(akcija, "inventory", 10) == 0){
        //printf("%s\n", player1->name);
        printInventory(*player1);
        preglednik = 1;
    }
    if(strncmp(akcija, "fight", 6) == 0){
        fight(player1, difficulty, permadeath);
        preglednik = 1;
    }
    if(strncmp(akcija, "title", 6) == 0){
        titleScreen(&difficulty, &permadeath, baseHealth, modifier);
        preglednik = 1;
    }
    if(strncmp(akcija, "save", 5) == 0){
        //printf("%s\n", filename(currentSave(*player1)));
        save(*player1, 0, filename(currentSave(*player1)));
        preglednik = 1;
    }
    if(preglednik == 0){
        printf("Unknown command\n");
    }
    free(akcija);
    tavern(player1, difficulty, permadeath, baseHealth, modifier);
}

/*int main(){

    Player player1 = createPlayer(20, 5);
    player1.coins = 200;
    //changeWeapon(&player1, &player1.inventorySize);
    //printf("%s %d %d\n", player1.weapons[0].name, player1.weapons[0].damage, player1.weapons[0].condition);
    tavern(&player1);

    //printf("%s %d\n",player1.weapons[player1.currentWeapon].name, strncmp(player1.weapons[player1.currentWeapon].name, "Fists", 5));
    printf("coins: %d\n", player1.coins);
    changeWeapon(&player1, &player1.inventorySize);
    return 0;
}*/