
int save(Player player1, int new_save, char* savefile);
Player newSave(int baseHealth, int modifier);
char listOfSaves();
char currentSave(Player current);
char* filename(char c);
void deleteSave(char* filename);
Player load(char* filename);