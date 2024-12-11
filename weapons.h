
char* weaponName();
int weaponDamage();
int weaponCondition();

typedef struct Weapon{
    int damage;
    int condition;
    char* name;
} Weapon;

int arrayLength(char** array);

Weapon createWeapon();
