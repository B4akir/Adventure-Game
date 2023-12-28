#include "big-m.h"







void initialInventory(Player *player){


    for (int i=0; i<5; i++){

        strcpy(player->inventory.items[i], ".");
        player->inventory.itemAssigned[i]=0;

    }

    

    switch (player->karakter){



  






        
        case'W' : 
        
            strcpy(player->inventory.items[0], "Sword");
            strcpy(player->inventory.itemTypes[0], "+Attack");
        break;
        case 'M':
            strcpy(player->inventory.items[0], "Staff");
            strcpy(player->inventory.itemTypes[0], "+Attack");
             
        break;
        case 'A':
            strcpy(player->inventory.items[0], "Bow");
            strcpy(player->inventory.itemTypes[0], "+Attack");
        break;

        
  
    }



  




}



