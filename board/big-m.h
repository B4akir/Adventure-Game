// matrix.h

#ifndef MATRIX_H
#define MATRIX_H

// Define matrix dimensions


// Define the matrix structure
typedef struct {
    char data[100][100];
} World;

// Function to initialize the global matrix
void initWorld(World *world);

#endif // MATRIX_H
