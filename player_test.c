#include <stdio.h>

typedef struct {
    int x,y;

}Player;

typedef struct {
    char karakter;
    char ime[20];
} Character;


typedef struct {
    char data[30][30];
} World;





void initWorld(World *world) {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            
          
         world->data[i][j] = ' ';
        }
    }
}





void ispis(World *world) {
    system("cls");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            printf("%c", world->data[i][j]);
        }
        printf("\n");
    }
}


void initalPosition(Player *player){ // pocetna pozicija playera

player->y= 0;
player->x= 0;


}; 

void movement(Player *player){ // player movement

char unos;

printf("Pomjeri se: \n");
scanf("%c",&unos);


switch (unos){
    case 'w':
    player->y--;
    break;
case 's':
    player->y++;
    break;
case 'd':
    player->x++;
    break;
case 'a':
    player->x--;
    break;

}

}


void kreator(Character *karakter) {
    printf("Unesite vase ime:\n");
    scanf("%19s", karakter->ime);

    // Clear the input buffer to prevent issues with the following character input
    while (getchar() != '\n');

    printf("Kako zelite izgledati? \nUnesite bilo koji ASCII karakter:\n");
    scanf(" %c", &karakter->karakter);
}

void initPlayer(Player *player, World *world, Character *karakter) {
  


    world->data[player->y][player->x] = karakter->karakter;
}


void dismatlePlayer(Player *player, World *world ){

world->data[player->y][player->x] = ' ';

}





int main (){

World world;
Character karakter;
Player player;


kreator(&karakter);

initalPosition(&player);
initWorld(&world);

while(1){
dismatlePlayer(&player,&world);
movement(&player);
initPlayer(&player,&world,&karakter);

ispis(&world);




}










}