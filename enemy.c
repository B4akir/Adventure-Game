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
    //put coordinates of enemies in each region in the middle of the region
    for (int i=0; i<5; i++){
        Region *region0 = &regions[i];
        region0->enemy.position.y = region0->position.y + region0->height / 2;
        region0->enemy.position.x = region0->position.x + region0->width / 2;

        // Initialize oldChar as '.' for all enemies
        region0->enemy.oldChar = '.';

        // Temporary enemy types
        char array[3] = {'R', 'B', 'G'};
        int randomNumber = rand() % 3; // Random enemy selection

        //Hardcode enemy as B
        region0->enemy.constKarakter = 'B';
        
        // Set enemy as alive
        region0->enemy.alive=1;
    }
}



// pomjeranje enemya
//pozvano je u enemySpawnActivation




// sve varijable dobija od enemySpawnActivation

void enemyLogic(World *world, Region *region, int index /* POTENCIJALNA GRESKA*/, Player *player){
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

    if (newArea == '.') {   //enemy se moze samo pomjerati unutar regije /* POTENCIJALNA GRESKA  */
        region0->enemy.oldChar = '.';
        region0->enemy.position.y = newY;
        region0->enemy.position.x = newX;
    }
    else if (newArea==player->karakter){
        initiateCombat(player, region);
    }
}


void enemySpawnActivation(Player *player, Region *region, World *world){
    //detect in which region the player is
    for(int i=0; i<5; i++){ // this sends indexes to all
        Region *region0 = &regions[i];
        checkHealth(region0);
        if (player->inRegion == i) {
            if (region0->enemy.alive==0){
                region0->enemy.karakter='.';
            }
            else if (region0->enemy.alive==1) {
                region0->enemy.oldChar='.';
                region0->enemy.karakter = region0->enemy.constKarakter;
                // start enemy movement
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


// deklarise enemije u svijet

void enemiesIntoWorld(World *world, Region *region){



//pokupi sve regije
for (int i=0;i<5;i++){



Region *region0 = &regions[i];


// stavlja enemya u svijet
    world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.karakter;




}




}

