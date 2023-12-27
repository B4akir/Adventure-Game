#include "big-m.h"



void checkHealth(Region *region0){
  if (region0->enemy.stats.health<=0){
    region0->enemy.alive=0;
  


  }

  else if (region0->enemy.stats.health>0){
  

    region0->enemy.alive=1;
  }


}


// pocetne statse playera
void initalStatsPlayer(Player *player ,int odabir){



switch (odabir){

case 1:
    player->stats.health=15;
    player->stats.attack=5;

    player->stats.constHealth=15;
    player->stats.constAttack=5;

    break;

  case 2:
    player->stats.health=5;
    player->stats.attack=14;

    player->stats.constHealth=5;
    player->stats.constAttack=14;

    break;

case 3:
    player->stats.health=10;
    player->stats.attack=10;

    player->stats.constHealth=10;
    player->stats.constAttack=10;

    break;

}



}


//pocetne statse enemya

void initalStatsEnemy(Region *region){


    for (int i=0;i<5;i++){


        Region *region0=&regions[i];
      switch(region0->enemy.constKarakter){
        case 'B':
        region0->enemy.stats.health=5;
        region0->enemy.stats.attack=3;

        break;
         case 'T':
             region0->enemy.stats.health=100;
             region0->enemy.stats.attack=30;

        break;
         case 'R':
             region0->enemy.stats.health=3;
             region0->enemy.stats.attack=10;

        break;
      }





        

     

    }

}







// pozvana kada player ili enemy zeli doci na mjesto enemya ili playera

// povezana sa enemyMovement i playerMovement

void initiateCombat(Player *player, Region *region){

for (int i=0; i<5; i++){



  Region *region0=&regions[i];

  if (player->inRegion==i){
          // uzima random broj od 0 do max napada playera
        int num1= rand() % player->stats.attack;

      // uzima random broj od 0 do max napada enemya
      int num2= rand() % region0->enemy.stats.attack;

      // odradi napade i player i enemy
      region0->enemy.stats.health=region0->enemy.stats.health-num1;
      printf("Enemy je napadnut za %d\n", num1);
      player->stats.health=player->stats.health-num2;
      printf("Player je napadnut za %d\n", num2);


  }
sleep (0.5);

}










}




    

    
    

