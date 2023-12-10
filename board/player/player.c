#include <stdio.h>
#include "player.h"

void initPlayer(Player *player){ // pocetna pozicija playera

player->y= HEIGHT/2;
player->x= WIDTH/2;


}; 


void movement(Player *player){ // player movement

char unos;

printf("---> \n");
scanf("%c",&unos);


switch (unos){
    case 'w':
    player->y--;
    break;
case 's':
    player->y++;
    break;
case 'd':
    player->x++;
    break;
case 'a':
    player->x--;
    break;

}

}