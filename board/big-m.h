// matrix.h

#ifndef MATRIX_H
#define MATRIX_H

// Define matrix dimensions
#define HEIGHT 10
#define WIDTH 20

// Define the matrix structure
typedef struct {
    char data[HEIGHT][WIDTH];
} Matrix;

// Function to initialize the global matrix
void initializeMatrix(Matrix *matrix);

#endif // MATRIX_H
