#include <stdio.h>
#include ".\shared\big-m.h"
#include "region.c"
#include "init_world.c"
#include ".\player\player_movement.c"
#include ".\player\init_player.c"
#include ".\shared\player.h"
#include ".\karakter_stvari\character_selection.c"
void regionInit(World *world);
void initWorld(World *world);
void kreator(Character *karakter);



void initPlayer(Player *player, World *world, Character *karakter);


void initalPosition( Player *player);
void movement(Player *player);


void ispis(World *world){

system("cls");
  for (int i=0;i<30;i++){
    for (int j=0;j<30;j++){

    printf("%c",world->data[i][j]);


    }
  printf("\n");
    
  }
}





int main (){

World world;
Player player;
Character karakter;


kreator(&karakter);
initalPosition(&player);
initWorld(&world);
regionInit(&world);

while (1){





initPlayer(&player,&world, &karakter);

ispis (&world);
movement(&player);


}





}
