#include <stdio.h>
#include <stdlib.h>
#include "board.c"


#define HEIGHT 10
#define WIDTH 20


 void boardCreation(Player *player);
 void movement(Player *player);
 void initPlayer(Player *player);


int main (){


Player player;

initPlayer(&player);

while (1){
boardCreation(&player);
movement(&player);
}

return 0;

}




