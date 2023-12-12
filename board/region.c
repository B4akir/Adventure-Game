#include <stdio.h>
#include <stdlib.h>
#include ".\shared\karakter.h"
#include ".\shared\big-m.h"
#include ".\shared\region.h"



void regionInit(Region *region){

    region->startX=3;
    region->startY=3;

      region->width=3;
    region->height=3;

   region->fillCharacter='.'; 



}


void regionIntoWorld(Region *region, World *world) {
    for (int i = region->startY; i < region->startY + region->height; i++) {
        for (int j = region->startX; j < region->startX + region->width; j++) {
            world->data[i][j] = region->fillCharacter;
        }
    }
}








