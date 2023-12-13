#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char data[30][30];
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
    char ime[20];
} Character;







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

void regionIntoWorld(Region *region, World *world) {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
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


    for (int i = 0; i < 3; i++) {
        regionIntoWorld(&regions[i], world);
    }
}















int main() {
    World world;
    Region region;
    Character karakter;



    initWorld(&world);
    initializeRegions(&world);
   

    ispis(&world);

int x;
    scanf("%d",x);
   



    return 0;
}
