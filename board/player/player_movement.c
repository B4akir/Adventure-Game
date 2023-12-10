#include <stdio.h>
#include "..\shared\player.h"



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