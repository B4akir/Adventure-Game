#include "big-m.h"



// Kada player udje u regiju enemy se aktivira, kada player izadje iz regije, enemy se deaktivira



   void enemyInit( Region *region, World *world){


//put coordinates of enemies in each region in the middle of the region


for (int i=0; i<5; i++){

Region *region0 = &regions[i];

region0->enemy.position.y = region0->position.y + region0->height / 2;
region0->enemy.position.x = region0->position.x + region0->width / 2;



// make it fully random


region0->enemy.oldChar = '.';

 char array[3] = {'S', 'O', 'W'};
       
        int randomNumber = rand() % 3;
       
        region0->enemy.constKarakter = 'B';





}
   }


void enemyLogic(Enemy *enemy, World *world, Region *region, int index, Player *player){

    Region *region0= &regions[index];
    
    

    world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.oldChar;
    int direction = rand() % 4; // Generate a random number between 0 and 3
char newX, newY;
    switch (direction) {
        case 0: // Move up
             newY=region0->enemy.position.y-1;
             newX=region0->enemy.position.x;
            break;
        case 1: // Move down
             newY=region0->enemy.position.y+1;
            newX=region0->enemy.position.x;
            break;
        case 2: // Move left
             newX=region0->enemy.position.x-1;
              newY=region0->enemy.position.y;
            break;
        case 3: // Move right
            newX=region0->enemy.position.x+1;
            newY=region0->enemy.position.y;
            break;
    }
char newArea = world->data[newY][newX];  // deklarisemo newArea da bi mogli provjeriti da li je validno mjesto za pokretanje



        if (newArea == '.') {  
        
        

        region0->enemy.oldChar = world->data[newY][newX];
        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            // salje u player strukturu nove kordinate playera
            region0->enemy.position.y = newY;
            region0->enemy.position.x = newX;
        }
    else if (newArea==player->karakter){
        initiateCombat(player, &region);


}

}


void enemySpawnActivation(Player *player, Region *region, World *world){

//detect in which region the player is

for(int i=0; i<5; i++){




Region *region0 = &regions[i];

// dadne 1 ako je player u regiji, dadne 0 ako je player izvan regije. Isptia svaku regiju, tkd zna u kojoj je regiji player.


    if ((player->position.y >= region0->position.y && player->position.y <= region0->position.y + region0->height) &&
        (player->position.x >= region0->position.x && player->position.x <= region0->position.x + region0->width)) {
            //spawn enemy in this region
       region0->enemy.active = 1;
       
      region0->enemy.oldChar='.';
       
        //make array of random characters and pick one out of 3

        region0->enemy.karakter = region0->enemy.constKarakter;
        enemyLogic(&region0->enemy, world, region, i, player);
    



    }
    else {

        //delete enemy in this region
       region0->enemy.active = 0;
       region0->enemy.karakter='.';
      


    }


 


}
}


void enemiesIntoWorld(World *world, Region *region){


for (int i=0;i<5;i++){

Region *region0 = &regions[i];

    world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.karakter;




}




}
 
//move enemy if enemy is active

