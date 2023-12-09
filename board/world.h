// matrix.h

#ifndef MATRIX_H
#define MATRIX_H

// Define matrix dimensions
#define ROWS 3
#define COLS 3

// Define the matrix structure
typedef struct {
    int data[ROWS][COLS];
} Matrix;

// Function to initialize the global matrix
void initializeMatrix(Matrix *matrix);

#endif // MATRIX_H
