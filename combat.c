#include "big-m.h"


void checkHealth(Region *region0){
  if (region0->enemy.stats.health<=0){
    region0->enemy.alive=0;
    printf("Dead");


  }

  else if (region0->enemy.stats.health>0){
     printf("Alive");

    region0->enemy.alive=1;
  }


}


// pocetne statse playera
void initalStatsPlayer(Player *player){


    player->stats.health=15;
    player->stats.attack=5;

    player->stats.constHealth=15;
    player->stats.constAttack=5;


}


//pocetne statse enemya

void initalStatsEnemy(Region *region){


    for (int i=0;i<5;i++){

        Region *region0=&regions[i];

        region0->enemy.stats.health=5;
        region0->enemy.stats.attack=3;

    }

}







// pozvana kada player ili enemy zeli doci na mjesto enemya ili playera

// povezana sa enemyMovement i playerMovement

void initiateCombat(Player *player, Region *region0){

// uzima random broj od 0 do max napada playera
int num1= rand() % player->stats.attack;

// uzima random broj od 0 do max napada enemya
int num2= rand() % region0->enemy.stats.attack;

// odradi napade i player i enemy
region0->enemy.stats.health=region0->enemy.stats.health-num1;
player->stats.health=player->stats.health-num2;








}




    

    
    

