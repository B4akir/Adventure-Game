#include <stdio.h>
#include "..\shared\player.h"
#include "..\shared\big-m.h"
#include "..\shared\karakter.h"



void initalPosition(Player *player){ // pocetna pozicija playera

player->y= 1;
player->x= 1;


}; 


void initPlayer(Player *player, World *world, Character *karakter){

world->data[player->y][player->x]=karakter->karakter;

}


