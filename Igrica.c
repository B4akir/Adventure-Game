#include <stdio.h>
#include <stdlib.h>
#include "Board\region.c"
#include "karakter_stvari\character_selection.c"
#include "karakter_stvari\karakter.h"


#define HEIGHT 10
#define WIDTH 20

//pocetak
 void kreator(Character *karakter);

//board
 void boardCreation(Player *player, Character *karakter);
 void movement(Player *player);
 void initPlayer(Player *player);






int main (){


//karakter dio

Character karakter;
 kreator(&karakter);



Player player;
initPlayer(&player);


while (1){
boardCreation(&player,&karakter);
movement(&player);
}

return 0;

}




