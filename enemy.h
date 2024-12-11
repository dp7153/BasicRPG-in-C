
char *race();
char *nameHumanoid();

typedef struct Enemy{
    char* race;
    char* name;
    int health;
    struct Weapon weapon;
} Enemy;

struct Enemy createEnemy();
void enemyAttack(Enemy *enemy, int* playerHealth);
