

typedef struct Player{
    char* name;
    int coins;
    int health;
    //Inventory inventory[];
    int currentWeapon;
    int inventorySize;
    struct Weapon weapons[5];
} Player;

Player createPlayer(int baseHealth, int modifier);