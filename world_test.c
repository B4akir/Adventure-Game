#include <stdio.h>

#define HEIGHT 40
#define WIDTH 40

typedef struct {
    int x,y;

}Player;

typedef struct {
    char karakter;
    char ime[20];
} Character;


typedef struct {
    char data[HEIGHT][WIDTH];
} World;


typedef struct {
    int startX, startY; // Switched startX and startY
    int width, height;
    char fillCharacter;
    int regionSize;
} Region;






//world

void initWorld(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            
          
         world->data[i][j] = ' ';
        }
    }
}





void ispis(World *world) {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", world->data[i][j]);
        }
        printf("\n");
    }
}




//player
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



//regions

void regionIntoWorld(Region *region, World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if ((i >= region->startY && i <= region->startY + region->height) &&
                (j >= region->startX && j <= region->startX + region->width)) {
                // Check if on the edge
                if (i == region->startY || i == region->startY + region->height ||
                    j == region->startX || j == region->startX + region->width) {
                    world->data[i][j] = '#';
                } else {
                    world->data[i][j] = region->fillCharacter;
                }
            }
        }
    }
}

void initializeRegions(World *world) {
    Region regions[5];

    regionInit(&regions[0]/*index*/, 0/*y*/, 0/*x*/, 7,/*height*/ 10, /*width*/'.' /*karakter*/);
    regionInit(&regions[1], 1, 15, 3, 12, '.');
    regionInit(&regions[2], 12, 1, 10, 10, '.');
    regionInit(&regions[3], 20, 5, 5, 10, '*');
    regionInit(&regions[4], 20, 5, 5, 10, '*');


    for (int i = 0; i < 5; i++) {
        regionIntoWorld(&regions[i], world);
    }
}


void regionInit(Region *region, int startY, int startX, int height, int width, char fillCharacter) {
    region->startY = startY;
    region->startX = startX;
    region->height = height;
    region->width = width;
    region->fillCharacter = fillCharacter;
}



int main (){

World world;
Character karakter;
Player player;
Region region;


//region    




kreator(&karakter);
initalPosition(&player);

while(1){

  
initWorld(&world);
initializeRegions(&world);


movement(&player);
initPlayer(&player,&world,&karakter);

ispis(&world);




}







}

/*

Todo list:

- Make hodjiks
- Restrict player movement to hodnjiks and regions
- Make appearing regions and hodnjiks
- Make doorways




*/