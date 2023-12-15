#include <stdio.h>

typedef struct {
    int x,y;
    int index;
}VrataK;

VrataK vrata[2]; // Array of VrataK structures

void initializeMatrix(int matrica[10][10]) {
    int vrataIndex = 0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if ((i==2 && j==2) || (i==4 && j==4)){
                vrata[vrataIndex].x = i;
                vrata[vrataIndex].y = j;
                vrata[vrataIndex].index = vrataIndex;
                vrataIndex++;
                matrica[i][j]=0; // Assuming you want to assign 0 when i==2 and j==2 or i==4 and j==4
            }
            else {
                matrica[i][j]=1;
            }
        }
    }
}

void printMatrix(int matrica[10][10]) {
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            printf ("%d",matrica[i][j]);
        }
        printf ("\n");
    }
}

void printVrataPositions() {
    for(int i = 0; i < 2; i++) {
        printf("Vrata %d su na poziciji %d %d\n", vrata[i].index, vrata[i].x, vrata[i].y);
    }
}

int main (){
    int matrica[10][10];

    system("cls");
    initializeMatrix(matrica);
    printMatrix(matrica);
    printVrataPositions();

    return 0;
}