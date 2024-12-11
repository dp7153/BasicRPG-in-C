#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allMyHeaders.h"

char* beriFileString(FILE *file);

char listOfSaves(){
    printf("Which save?\n");
    //printf("%d\n", c);
    FILE* save1 = fopen("Savegame1.dat", "r");
    if(strncmp(beriFileString(save1), "", 10) != 0){
        rewind(save1);
        printf("1: %s\n", beriFileString(save1));
    }
    else{
        printf("1: EMPTY\n");
    }
    FILE* save2 = fopen("Savegame2.dat", "r");
    if(strncmp(beriFileString(save2), "", 10) != 0){
        rewind(save2);
        printf("2: %s\n", beriFileString(save2));
    }
    else{
        printf("2: EMPTY\n");
    }
    FILE* save3 = fopen("Savegame3.dat", "r");
    if(strncmp(beriFileString(save3), "", 10) != 0){
        rewind(save3);
        printf("3: %s\n", beriFileString(save3));
    }
    else{
        printf("3: EMPTY\n");
    }
    FILE* save4 = fopen("Savegame4.dat", "r");
    if(strncmp(beriFileString(save4), "", 10) != 0){
        rewind(save4);
        printf("4: %s\n", beriFileString(save4));
    }
    else{
        printf("4: EMPTY\n");
    }
    FILE* save5 = fopen("Savegame5.dat", "r");
    if(strncmp(beriFileString(save5), "", 10) != 0){
        rewind(save5);
        printf("5: %s\n", beriFileString(save5));
    }
    else{
        printf("5: EMPTY\n");
    }
    FILE* save6 = fopen("Savegame6.dat", "r");
    if(strncmp(beriFileString(save6), "", 10) != 0){
        rewind(save6);
        printf("6: %s\n", beriFileString(save6));
    }
    else{
        printf("6: EMPTY\n");
    }
    //printf("0: back\n");
    
    char c = getchar();
    while(c < 48){
        c = getchar();
    }
    
    fclose(save1);
    fclose(save2);
    fclose(save3);
    fclose(save4);
    fclose(save5);
    fclose(save6);

    //printf("%d\n", c);
    return c;
}

Player load(char* filename);

char currentSave(Player current){
    char c = '1';
    for(int i = 0; i < 6; i++){
        Player p1 = load(filename(c));
        //printf("%d\n", c);
        if(strncmp(current.name, p1.name, 100) == 0){ //current.name == p1.name){
            //printf("%c\n", c);
            return c;
        }
        c++;
    }
    return '0';
}

char* filename(char c){
    if(c == '0'){
        return NULL;
    }
    char* ime = (char*) calloc(14, sizeof(char));
    strncpy(ime, "Savegame", 8);
    strncat(ime, &c, 1);
    strncat(ime, ".dat", 4);
    ime[13] = '\0';
    //printf("%s\n", ime);
    return ime;
}

void deleteSave(char* filename){
    FILE* file = fopen(filename, "w");
    fputc('\n', file);
    fclose(file);
}

int save(Player p1, int new_save, char* savefile);

Player newSave(int baseHealth, int modifier){

    char* savefile = filename(listOfSaves());
    //printf("%s\n", savefile);

    printf("Please enter your player name\n");
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
    ime[dolzinaImena /*+ 1*/] = '\0';
    //printf("%s\n", ime);

    Player p1 = createPlayer(baseHealth, modifier);

    p1.name = ime;
    //printf("%s\n", p1.name);

    save(p1, 1, savefile);
    free(ime);
    p1 = load(savefile);

    return p1;
}

int save(Player p1, int new_save, char* savefile){

    FILE* file = fopen(savefile, "w");
    if(file == NULL){
        printf("Couldn't save\n");
        return 1;
    }
    fprintf(file, "%s, %d, %d, %d, %d\n", p1.name, p1.coins, p1.health, p1.currentWeapon, p1.inventorySize);
    //printf("%s, %d, %d, %d, %d\n", p1.name, p1.coins, p1.health, p1.currentWeapon, p1.inventorySize);
    for(int i = 0; i < p1.inventorySize; i++){
        if(p1.weapons[i].damage < 1 || p1.weapons[i].condition < 1){
            //printf("LOL %d\n", i);
            break;
        }
        fprintf(file, "%s, %d, %d\n", p1.weapons[i].name, p1.weapons[i].damage, p1.weapons[i].condition);
    }
    rewind(file);
    fclose(file);     //WHY???????  nevermind, fixed itself :o
    if(new_save == 0){
        printf("Game saved successfully!\n");
    }
    return 0;
}

int preskociVejico(FILE* file, char c){
    if(c == ',' /*|| c == '\n'*/){
        fgetc(file);
    }
    return 0;
}

int beriChar(FILE* file, int* st){
    char c = fgetc(file);
    //printf("1: %c\n", c);
    c -= '0';
    int s = c;
    //printf("   %d\n", s);
    while(c != ' ' && c != ',' && c != '\n'){
        c = fgetc(file);
        //printf("2:\"%c\"\n", c);
        if(c != ' ' && c != ',' && c != '\n'){
            //printf("3: %c\n", c);
            //printf("   %d\n", s);
            c -= '0';
            s *= 10;
            s += c;
        }
        //printf("%d\n", s);
    }
    if(c == EOF){
        return 0;
    }
    //c -= '0';
    *st = s;
    //printf("\"%d\"\n", *st);
    preskociVejico(file, c);
    //preskociVejico(file, c);
    return 0;
}

char* beriFileString(FILE *file){
    //char *ime = (char*)calloc(100, sizeof(char));
    char temp[100];
    //printf("%s\n", ime);
    char c = fgetc(file);
    int stevec = 0;
    while(c != ',' && c != EOF && c != '\n'){
        temp[stevec] = c;
        c = fgetc(file);
        stevec++;
    }
    //rewind(file);
    char *ime = (char*)calloc(stevec + 1, sizeof(char));
    for(int i = 0; i < stevec; i++){
        ime[i] = temp[i];
    }
    ime[stevec] = '\0';

    preskociVejico(file, c);

    return ime;
}

int stOrozij(char* filename){

    int st = 0;
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("No file\n");
        exit(0);
    }

    char c = fgetc(file);
    while(c != EOF){
        //printf("%c", c);
        if(c == '\n'){
            st++;
        }
        c = fgetc(file);
    }

    rewind(file);
    st--;

    fclose(file);
    return st;
}

Player load(char* filename){
    Player p1 = createPlayer(1, 1);
    int orozij = stOrozij(filename);
    //printf("%d\n", orozij);

    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("Couldn't load\n");
        exit(1);
    }
    
    //printf("%d\n", orozij);

    //Player
    p1.name = beriFileString(file);
    //printf("%s %d\n", p1.name, d);
    beriChar(file, &p1.coins);
    beriChar(file, &p1.health);
    beriChar(file, &p1.currentWeapon);
    beriChar(file, &p1.inventorySize);


    //Weapons
    for(int i = 0; i < orozij; i++){
        //printf("Weapon %d:\n", i);
        p1.weapons[i].name = beriFileString(file);
        beriChar(file, &p1.weapons[i].damage);
        beriChar(file, &p1.weapons[i].condition);
        //fscanf(file, "%d, %d\n", &p1->weapons[i].damage, &p1->weapons[i].condition);
    }


    rewind(file);
    fclose(file);
    return p1;
}


/*int main(){

    Player p1 = newSave(20, 1);
    p1.weapons[1] = createWeapon();
    //p1.inventorySize++;
    p1.weapons[2] = createWeapon();
    //p1.inventorySize++;
    save(p1);

    Player p2 = load();
    printf("%d\n", p2.inventorySize);
    printf("%s %d %d %d %d\n", p2.name, p2.coins, p2.health, p2.currentWeapon, p2.inventorySize);
    for(int i = 0; i < p2.inventorySize; i++){
        if(p2.weapons[i].damage < 1 || p2.weapons[i].condition < 1){
            //printf("LOL %d\n", i);
            
            break;
        }
        printf("weapon %d: %s %d %d\n", i, p2.weapons[i].name, p2.weapons[i].damage, p2.weapons[i].condition);
    }
    int k = 3;
    printf("\n%s %d %d\n", p2.weapons[k].name, p2.weapons[k].damage, p2.weapons[k].condition);
    
    //printf("%s\n", p1.weapons[1].name);
    /*printf("%s %d %d %d %d\n", p1.name, p1.coins, p1.health, p1.currentWeapon, p1.inventorySize);

    for(int i = 0; i < p1.inventorySize; i++){
        if(p1.weapons[i].damage < 1 || p1.weapons[i].condition < 1){
            //printf("LOL %d\n", i);
            break;
        }
        printf("%s %d %d\n", p1.weapons[i].name, p1.weapons[i].damage, p1.weapons[i].condition);
    }*/

   //return 0;
//}