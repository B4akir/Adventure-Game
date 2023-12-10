#include <stdio.h>
#include "big-m.h"




void initializeMatrix(Matrix *matrix){


for (int i=0;i<10;i++){
  for (int j=0;j<20;j++){

if (i==5 && j==5){

matrix->data[i][j]='w';

}

else{

  matrix->data[i][j]='.';
}



  }
}


for (int i=0; i<10; i++){
  for (int j=0; j<20; j++){

    printf("%c",matrix->data[i][j]);
  }
  printf("\n");
}






}


int main (){

Matrix matrix;

initializeMatrix(&matrix);




}
