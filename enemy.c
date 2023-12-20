#include "big-m.h"



// Kada player udje u regiju enemy se aktivira, kada player izadje iz regije, enemy se deaktivira







void enemySpawnActivation(Player *player, Region *region, World *world){

//detect in which region the player is

for(int i=0; i<5; i++){




Region *region0 = &regions[i];

// dadne 1 ako je player u regiji, dadne 0 ako je player izvan regije. Isptia svaku regiju, tkd zna u kojoj je regiji player.


    if ((player->position.y >= region0->position.y && player->position.y <= region0->position.y + region0->height) &&
        (player->position.x >= region0->position.x && player->position.x <= region0->position.x + region0->width)) {
       region0->enemy.active = 1;

        region0->enemy.karakter='3';
        region0->enemy.position.y = region0->position.y + region0->height / 2;
        region0->enemy.position.x = region0->position.x + region0->width / 2;

        world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.karakter;
        


    }
    else {
       region0->enemy.active = 0;
        region0->enemy.karakter='.';
        world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.karakter;


    }


 


}
}



void enemyMovemeny();



