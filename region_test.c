#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char data[50][50];
} World;

typedef struct {
    int startX, startY; // Switched startX and startY
    int width, height;
    char fillCharacter;
    int regionSize;
} Region;

void regionInit(Region *region, int startY, int startX, int height, int width, char fillCharacter) {
    region->startY = startY;
    region->startX = startX;
    region->height = height;
    region->width = width;
    region->fillCharacter = fillCharacter;
}



typedef struct {
    int x,y;

}Player;

typedef struct {
    char karakter;
    char ime[30];
} Character;


   Region regions[6];



void initWorld(World *world) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            world->data[i][j] = ' ';
        }
    }
}

void ispis(World *world) {
    system("cls");
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            printf("%c", world->data[i][j]);
        }
        printf("\n");
    }
}

void regionIntoWorld(Region *region, World *world) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if ((i >= region->startY && i <= region->startY + region->height) &&
                (j >= region->startX && j <= region->startX + region->width)) {
                // Check if on the edge
                if (i == region->startY || i == region->startY + region->height ||
                    j == region->startX || j == region->startX + region->width) {
                    world->data[i][j] = '+';


                    
                } 
                
                
                
                else {
                    world->data[i][j] = region->fillCharacter;
                }
           
               
            }
        }
    }
}





 

void doorL(Region *region, World *world,int index){
    Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int height = region0->height;
    int width = region0->width;
    char character = region0->fillCharacter;

    printf("y: %d\n", y);
    printf("x: %d\n", x);
    printf("height: %d\n", height);
    printf("width: %d\n", width);
    printf("character: %c\n", character);


int i=(y+height)/2;


world->data[i][x] = '#';

printf("i: %d\n", i);


}

    // Now you can use x, y, width, height, and character







void doorR(Region *region, World *world){





}

void doorT(Region *region, World *world){





}

void doorB(Region *region, World *world){





}


void initializeRegions(World *world) {
    regionInit(&regions[0], /* y*/1,   /* x*/ 0, /* height*/ 7,  /* width*/  10, '.');
    regionInit(&regions[1], 1, 30, 5, 12, '1');
    regionInit(&regions[2], 12, 1, 5, 15, '2');
    regionInit(&regions[3], 25, 5, 5, 10, '3');
    regionInit(&regions[4], 10, 30, 5, 10, '4');
    regionInit(&regions[5], 25, 30, 5, 5, '5');

    for (int i = 0; i < 6; i++) {
        regionIntoWorld(&regions[i], world);
    }
}

















int main() {
    World world;
    Region region;
    Character karakter;
  


    initWorld(&world);
    initializeRegions(&world);
   
   doorL(&region, &world,1);
    ispis(&world);
 doorL(&region, &world,1);
int x;
    scanf("%d",x);
   



    return 0;
}
