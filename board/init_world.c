#include <stdio.h>
#include ".\shared\big-m.h"

void initWorld(World *world){


  for (int i=0;i<30;i++){
    for (int j=0;j<30;j++){

    world->data[i][j]=' ';


    }
  }
}