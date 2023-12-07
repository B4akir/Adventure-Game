#include <stdio.h>

void boardCreation();




typedef struct {
    int x,y;

}Player;

void initPlayer();


int main (){



boardCreation(2,3);


return 0;

}




void boardCreation(int x,int y)
{
int HEIGHT = 10;
int WIDTH= 20;

system("cls");

for (int i=0;i<HEIGHT;i++){
    
   
for (int j=0;j<WIDTH;j++){
    
    if (i==x && j==y){
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



