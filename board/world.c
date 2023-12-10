#include <stdio.h>
#include "big-m.h"




void initWorld(World *world){


for (int i=0;i<100;i++){
  for (int j=0;j<100;j++){

if (i==5 && j==5){

world->data[i][j]='w';

}

else{

  world->data[i][j]='.';
}



  }
}


for (int i=0; i<100; i++){
  for (int j=0; j<100; j++){

    printf("%c",world->data[i][j]);
  }
  printf("\n");
}






}


int main (){

World world;

initWorld(&world);




}
