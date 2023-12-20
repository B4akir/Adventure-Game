#include "big-m.h"



void initalStatsPlayer(Player *player){


    player->stats.health=15;
    player->stats.attack=5;

    player->stats.constHealth=15;
    player->stats.constAttack=5;


}

void initalStatsEnemy(Region *region){


    for (int i=0;i<5;i++){

        Region *region0=&regions[i];

        region0->enemy.stats.health=5;
        region0->enemy.stats.attack=3;

    }

}


void initiateCombat(Player *player, Region *region){


    Region *region0=&regions[0];

            player->stats.health=  player->stats.health  -  region0->enemy.stats.attack;
    
    



}