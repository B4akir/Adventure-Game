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


int num1= rand() % player->stats.attack;

int num2= rand() % region0->enemy.stats.attack;


   


    //player udari zivotinju
if (num1!=0){

    region->enemy.stats.health= region->enemy.stats.health - num1;


}

     else if(num1<=0){
        
        //miss

     }

if (num2!=0){


player->stats.health= player->stats.health - num2;

}


else if (num2!=0){

//miss

}



    if (region0->enemy.stats.health<=0){

        region0->enemy.karakter='.';

    }

    if (player->stats.health<=0){

        player->karakter='X';

    }

    
    //
    
    
    



}