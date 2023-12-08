#include <stdio.h>
#include <stdlib.h>
#include "Board\board.c"
#include "karakter_stvari\character_selection.c"


#define HEIGHT 10
#define WIDTH 20



//board
 void boardCreation(Player *player);
 void movement(Player *player);
 void initPlayer(Player *player);


//pocetak
 void kreator(Character *karakter);



int main (){


//karakter dio

Character karakter;
 kreator(&karakter);


printf("%c",karakter.karakter);

Player player;
initPlayer(&player);


while (1){
boardCreation(&player);
movement(&player);
}

return 0;

}




