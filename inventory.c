#include "big-m.h"







void initialInventory(Player *player){




    switch (player->karakter){

        case'W' : 
       strcpy(player->inventory.items[0], "Sword");
        break;
        case 'M':
            strcpy(player->inventory.items[0], "Staff");
        break;
        case 'A':
            strcpy(player->inventory.items[0], "Bow");
        break;



    }



  




}