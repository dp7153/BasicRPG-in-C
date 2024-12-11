#include <stdio.h>
#include <stdlib.h>
#include "allMyHeaders.h"

void slash(int iteracija, int sirinaZnaka){
    if(iteracija == 0){
        return;
    }
    for(int i = 0; i < sirinaZnaka; i++){
        printf("/");
    }printf("\n");
    slash(iteracija - 1, sirinaZnaka);
}

void splashScreen(int iteracija, int sirinaZnaka){
    slash(iteracija, sirinaZnaka);
    for(int i = 0; i < sirinaZnaka * 45 / 100; i++){
        printf(" ");
    }
    printf("Very good RPG\n");
    for(int i = 0; i < sirinaZnaka * 40 / 100; i++){
        printf(" ");
    }
    printf("Press ENTER to continue\n");
    slash(iteracija, sirinaZnaka);
    getchar();
}

int difficultySetting(){
    printf("Select difficulty:\nvery easy[0]\neasy[1]\nmedium[2]\nhard[3]\n");
    getchar();
    return getchar() - '0';
}

int permadeathSetting(){
    int permadeath = 0;
    printf("permadeath? [y/n]\n");
    getchar();
    if(getchar() == 'y'){
        permadeath = 1;
    }
    return permadeath;
}

Player titleScreen(int *difficulty, int *permadeath, int baseHealth, int modifier);
void settingsPage(int *difficulty, int *permadeath, int baseHealth, int modifier){
    printf("Difficulty[1]\n\n");
    printf("Permadeath[2]\n\n");
    printf("Back[3]\n\n");

    getchar();
    char c = getchar() - '0';
    if(c == 1){
        *difficulty = difficultySetting();
    }
    else if(c == 2){
        *permadeath = permadeathSetting();
    }
    else if(c == 3){
        titleScreen(difficulty, permadeath, baseHealth, modifier);
    }
    titleScreen(difficulty, permadeath, baseHealth, modifier);
}

Player titleScreen(int *difficulty, int *permadeath, int baseHealth, int modifier){
    printf("\nNew Game[1]\n\n");
    printf("Continue[2]\n\n");
    printf("Load Game[3]\n\n");
    printf("Settings[4]\n\n");
    printf("Exit[5]\n\n");
    printf("Delete Save [6]\n");

    int odlocitev = getchar() - '0';
    if(odlocitev == -38){               //vrže nek linefeed
        odlocitev = getchar() - '0';
    }
    //printf("\n%d\n", odlocitev);
    switch(odlocitev){
        case 1:
            //printf("Not yet implemented\n");
            printf("\n");
            *difficulty = difficultySetting();
            if(*difficulty == 0){
                modifier *= 5;
            }
            else if(*difficulty == 1){
                modifier *= 3;
            }
            else if(*difficulty == 2){
                modifier *= 1.5;
            }
            printf("\n");
            *permadeath = permadeathSetting();
            printf("\n");
            return newSave(baseHealth, modifier);
            break;
        case 2:
            printf("Not yet implemented\n");
            //return load();
            break;
        case 3: ;
            //printf("Not yet implemented\n");
            char* ime = filename(listOfSaves());
            return load(ime);
            break;
        case 4:
            settingsPage(difficulty, permadeath, baseHealth, modifier);
            break;
        case 5:
            exit(0);
            break;
        case 6:
            printf("Which Save?\n");
            char c = getchar();
            if(c < 49){
                c = getchar();
            }
            deleteSave(filename(c));
            titleScreen(difficulty, permadeath, baseHealth, modifier);
            break;
    }
}