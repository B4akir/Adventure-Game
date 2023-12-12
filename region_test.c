#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char data[30][30];
} World;

typedef struct {
    int startX, startY;
    int width, height;
    char fillCharacter;
    int regionSize;
} Region;

void regionInit(Region *region) {
    region->startX = 3;
    region->startY = 10;
    region->width = 6;
    region->height = 10;
    region->fillCharacter = 'O';

    printf("Region x: %d, Region y: %d, Region width: %d, Region height: %d, Region char: %c\n",
           region->startX, region->startY, region->width, region->height, region->fillCharacter);
}

void initWorld(World *world) {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            world->data[i][j] = ' ';
        }
    }
}

void ispis(World *world, Region *region) {
    system("cls");
    for (int i = 0; i <30;  i++) {
        for (int j = 0; j < 30; j++) {
            printf("%c", world->data[i][j]);
        }
        printf("\n");
    }
}

void regionIntoWorld(Region *region, World *world) {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if ((i >= region->startX && i <= region->startX + region->height) &&
                (j >= region->startY && j <= region->startY + region->width)) {
                world->data[i][j] = region->fillCharacter;
            }
        }
    }
}


int main() {
    Region region;
    World world;

    initWorld(&world);
    regionInit(&region);
    
    regionIntoWorld(&region, &world);
    ispis(&world, &region);

    return 0;
}
