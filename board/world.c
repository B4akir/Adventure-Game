#include <stdio.h>
#include "region.c"
#include <stdlib.h>
#include "..\karakter_stvari\character_selection.c"
#include "..\karakter_stvari\karakter.h"


#define wHEIGHT 12
#define wWIDTH 8




 int main(){
    
Character karakter;
 kreator(&karakter);



Player player;
initPlayer(&player);



 system ("cls");

for (int i=0;i<wHEIGHT;i++){
    
   
for (int j=0;j<wWIDTH;j++){
     
     if (i<6 && j>4){
        boardCreation(&player,&karakter);
     }
     
     
     else{printf("0");}   
    }
    printf("\n");
}

 
}
 
