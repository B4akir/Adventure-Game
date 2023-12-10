#include <stdio.h>
#include "big-m.h"
#include "region.c"

void regionInit(World *world);

void initWorld(World *world){


  for (int i=0;i<100;i++){
    for (int j=0;j<100;j++){

    world->data[i][j]=' ';


    }
  }
}


void ispis(World *world){


  for (int i=0;i<100;i++){
    for (int j=0;j<100;j++){

    printf("%c",world->data[i][j]);


    }

    printf("\n");
  }
}





int main (){

World world;

initWorld(&world);
regionInit(&world);
ispis (&world);




}
