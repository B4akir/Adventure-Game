#include <stdio.h>
#include <stdlib.h>

void boardCreation();

#define HEIGHT 10
#define WIDTH 20




typedef struct {
    int x,y;

}Player;

void initPlayer(Player *player){

player->x= HEIGHT/2;
player->y= WIDTH/2;


};


int main (){


Player player;

initPlayer(&player);


boardCreation(&player);


return 0;

}




void boardCreation(Player *player)
{



system("cls");

for (int i=0;i<HEIGHT;i++){
    
   
for (int j=0;j<WIDTH;j++){
    
    if (i==player->x && j==player->y){
        printf("@");
    }
    else{
        printf(".");
    }
}
 printf("\n");
}



}

// void initPlayer(Player *player){

//     player->x=WIDTH/2;
//     player->y=WIDHT/2;


// }



