#ifndef REGION_H
#define REGION_H


typedef struct {
    int startX, startY;   // Starting position of the region 
    int width, height;    // Dimensions of the region
    char fillCharacter;   // Character to fill the region
} Region;


void regionInit(Region *region, World *world);

#endif // REGION_H