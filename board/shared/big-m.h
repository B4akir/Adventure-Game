// matrix.h

#ifndef MATRIX_H
#define MATRIX_H
#include "player.h"
#include "karakter.h"
#include "region.h"
// Define matrix dimensions


// Define the matrix structure
typedef struct {
    char data[30][30];
} World;

// Function to initialize the global matrix
void initWorld(World *world);
void initPlayer(Player *player, World *world, Character *karakter);
void regionIntoWorld(Region *region, World *world)

#endif // MATRIX_H
