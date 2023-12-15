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