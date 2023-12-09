#include <stdio.h>
#include <stdlib.h>
#include "..\karakter_stvari\karakter.h"
#include "world.h"


#define HEIGHT 10
#define WIDTH 20

typedef struct {
    int x,y;

}Player;



// main
 void boardCreation(Player *player, Character *karakter);
 void movement(Player *player);
 void initPlayer(Player *player);
 






void initPlayer(Player *player){

player->y= HEIGHT/2;
player->x= WIDTH/2;


};


void movement(Player *player){

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













 void boardCreation(Player *player,Character *karakter){
    
 system ("cls");

for (int i=0;i<HEIGHT;i++){
    
   
for (int j=0;j<WIDTH;j++){
    
    if (i==player->y && j==player->x){
        printf("%c",karakter->karakter);
    }
    else{
        printf("1");
    }
}
printf("\n");
 
}






}




