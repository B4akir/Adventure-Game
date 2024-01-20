#include "big-m.h"


void isInRegion (Region *region, Player *player){





for (int i=0; i<5; i++){
    Region *region0 = &regions[i];
    if ((player->position.y >= region0->position.y - 2 && player->position.y <= region0->position.y + region0->height + 2) &&
        (player->position.x >= region0->position.x - 2 && player->position.x <= region0->position.x + region0->width + 2)) {
        player->inRegion=i;
    }
}
}

// Kada player udje u regiju enemy se aktivira, kada player izadje iz regije, enemy se deaktivira

void enemyInit(Region *region, World *world){
    
    for (int i=0; i<5; i++){
        Region *region0 = &regions[i];
        region0->enemy.position.y = region0->position.y + region0->height / 2;
        region0->enemy.position.x = region0->position.x + region0->width / 2;

        
        region0->enemy.oldChar = '.';

    
        if (i==0 ){
              region0->enemy.constKarakter = 'B';
              strcpy(region0->enemy.ime, "Bat");
        }


        else if (i==1){
            region0->enemy.constKarakter = 'R';
            strcpy(region0->enemy.ime, "Rat");
        }
      else if (i==2){

        region0->enemy.constKarakter = 'T';
        strcpy(region0->enemy.ime, "Troll");

      } 
      else if (i==3){
        region0->enemy.constKarakter = 'B';
        strcpy(region0->enemy.ime, "Bat");
      }

      else if (i==4){
        region0->enemy.constKarakter = 'R';
        strcpy(region0->enemy.ime, "Rat");
      }
        
       
        region0->enemy.alive=1;
    }
}


void enemyLogic(World *world, Region *region, int index , Player *player){
    Region *region0= &regions[index]; 

    world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.oldChar;

int newX, newY;

//bat pomjeranje
    if (region0->enemy.constKarakter=='B'){



 
    int direction = rand() % 5;

    //bat movement
    switch (direction) {
        case 0: 
             newY=region0->enemy.position.y-1;
             newX=region0->enemy.position.x;
            break;
        case 1: 
             newY=region0->enemy.position.y+1;
            newX=region0->enemy.position.x;
            break;
        case 2: 
             newX=region0->enemy.position.x-1;
              newY=region0->enemy.position.y;
            break;
        case 3: 
            newX=region0->enemy.position.x+1;
            newY=region0->enemy.position.y;
            break;

        case 4:
            newX=region0->enemy.position.x;
            newY=region0->enemy.position.y;
    
    }
    }
    //troll movement
    else if (region0->enemy.constKarakter=='T'){


        int sleep;
        sleep = rand() % 4;


    if (sleep==0){
            
      // enemy pathfinding do playera
        //player sa desne strane enemya
        if (player->position.x > region0->enemy.position.x) {
            newX=region0->enemy.position.x+1;
            newY=region0->enemy.position.y;
        }
        //player sa lijeve strane enemya
        else if (player->position.x < region0->enemy.position.x) {
            newX=region0->enemy.position.x-1;
            newY=region0->enemy.position.y;
        }
        //player sa donje strane enemya
        else if (player->position.y > region0->enemy.position.y) {
           newY= region0->enemy.position.y+1;
           newX=region0->enemy.position.x;
        }
        //player sa gornje strane enemya
        else if (player->position.y < region0->enemy.position.y) {
           newY= region0->enemy.position.y-1;
           newX=region0->enemy.position.x;
        }

    }

    else if (sleep>0){
        newX=region0->enemy.position.x;
        newY=region0->enemy.position.y;
    }
    }
   
    

    else if (region0->enemy.constKarakter=='R'){


 int random = rand() % 3;
            
       // enemy pathfinding do playera
       
        if (player->position.x > region0->enemy.position.x) {
            newX=region0->enemy.position.x+random;
            newY=region0->enemy.position.y;
        }
        
        else if (player->position.x < region0->enemy.position.x) {
            newX=region0->enemy.position.x-random;
            newY=region0->enemy.position.y;
        }
        
        else if (player->position.y > region0->enemy.position.y) {
           newY= region0->enemy.position.y+random;
           newX=region0->enemy.position.x;
        }
        
        else if (player->position.y < region0->enemy.position.y) {
           newY= region0->enemy.position.y-random;
           newX=region0->enemy.position.x;
        }

    }

   
    


    char newArea = world->data[newY][newX];  

    if (newArea == '.') {   
        region0->enemy.oldChar = '.';
        region0->enemy.position.y = newY;
        region0->enemy.position.x = newX;
    }
    else if (newArea==player->karakter){
        if (region0->enemy.karakter=='R'){
                 
                 int random = rand() % 2;

                 if (random==0){
                    initiateCombat(player, region);
                 }
                 else if (random==1){
                    region0->enemy.position.y = newY;
                    region0->enemy.position.x = newX;
                 }
        }

        else {
         initiateCombat(player, region);
        region0->enemy.position.y = newY;
        region0->enemy.position.x = newX;

        }
       
    }

}







void enemySpawnActivation(Player *player, Region *region, World *world){
   
    for(int i=0; i<5; i++){ 
        Region *region0 = &regions[i];
        checkHealth(region0);
        if (player->inRegion == i) {
            if (region0->enemy.alive==0){
                region0->enemy.karakter='.';
            }
            else if (region0->enemy.alive==1) {
                region0->enemy.oldChar='.';
                region0->enemy.karakter = region0->enemy.constKarakter;
                
                enemyLogic( world, region, player->inRegion, player);
            }
        }
        else {
            if(region0->populated == 1) {
                region0->enemy.karakter='.';
            }
            else {
                region0->enemy.karakter=' ';
            }
        }
    }
}



void enemiesIntoWorld(World *world, Region *region){




for (int i=0;i<5;i++){



Region *region0 = &regions[i];



    world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.karakter;




}




}

