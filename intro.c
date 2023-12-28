#include "big-m.h"






   void initWorldIntro(World *world) {
        for (int i = 0; i < INTROHEIGHT; i++) {
            for (int j = 0; j < INTROWIDTH; j++) {
            
            if (i==9 && j<=20 ){
                world->data[i][j] = 220;
            }

            else if (i==12 && j<=20){
                world->data[i][j]=220;
            }
          
// pod
          else if (i == 6 && (j<=9 && j>=3)){
            world->data[i][j] = '#';
          }
//plafon
            else if (i == 3 && (j<=9 && j>=3)){
            world->data[i][j] = '#';
          }



//desni zid
           else if ((i<=6 && i>=3)&&  j==9){
            world->data[i][j] = '#';
          }
//lijevi zid
   else if ((i<=6 && i>=3)&&  j==3){
            world->data[i][j] = '#';
          }

// vrata
else if (i==5 && j==6){
    world->data[i][j] = 254;

}


//krov

else if (i==0 && (j>=5 && j<=7)){
    world->data[i][j] = 94;
}

else if (i==1 && (j==4 || j==8)){
    world->data[i][j] = 94;
}

else if  (i==2 && (j==3 || j==9)){
    world->data[i][j] = 94;

}








          else{
                world->data[i][j] = '.';
          }
            
            }
        }
    }




 void ispisIntro(World *world) {


// Ovo je samo za prvu regiju, treba napraviti za sve regije



// izbrise prosli ispis
    system("cls");

    // isprinta world
    char buffer[INTROHEIGHT * (INTROWIDTH + 1) + 1]; // +1 for each newline and +1 for null terminator
    char *p = buffer;
    for (int i = 0; i < INTROHEIGHT; i++) {
        for (int j = 0; j < INTROWIDTH; j++) {
            *p++ = world->data[i][j];
        }
        *p++ = '\n';
    }
    *p = '\0'; // null terminate the string
    
    
    // ispise statse playera i enemya
    printf("%s", buffer);

    

}

void putXOnEdgesIntro(World *world) {
    int rows = sizeof(world->data) / sizeof(world->data[0]);
    int cols = sizeof(world->data[0]) / sizeof(world->data[0][0]);

    // Put 'x' on the top and bottom edges
    for (int i = 0; i < INTROHEIGHT; i++) {
        world->data[0][i] = 'x';
        world->data[rows - 1][i] = 'x';
    }

    // Put 'x' on the left and right edges
    for (int i = 0; i < INTROWIDTH; i++) {
        world->data[i][0] = 'x';
        world->data[i][cols - 1] = 'x';
    }
}










void intro (Player *player){


    World worldIntro;
    
        
        
        initWorldIntro(&worldIntro);
       
        worldIntro.data[10][0] = '?';
        for (int i=1;i<10;i++){


            if (i==9){
                   sleep(1);
                printf("Jos jedan dosadan dan u Gracanici...\n");
                // sleep(3);
            }
            worldIntro.data[10][i-1] = '.';
            worldIntro.data[10][i] = '?';
             ispisIntro(&worldIntro);
            //  sleep(1);
            
 
        }

        worldIntro.data[11][15] = '?';
         for (int i=15;i>2;i--){


            if (i==10){
               // sleep (1);
                printf("Zdravo Izikijale \n");
                sleep (2);
                printf("...");
                printf("Zdravo Harune?");
               // sleep (2);

            }

            worldIntro.data[11][i+1] = '.';
            worldIntro.data[11][i] = 'H';
            
            
             ispisIntro(&worldIntro);
           //  sleep (1);
          
        }
     
       printf("Ne znam zasto me zove Izikijal, kako cudan covjek...\n");
       // sleep (3);
       printf("Trebo bi mu reci da se zapravo zovem _______ \n");
        ime (player);
      
  
       //sleep (3);
       //ime funkcija


       
     
 worldIntro.data[10][10] = '?';
        for (int i=10;i<=15;i++){


            if (i==15){
                   sleep(1);
                   printf("*trk *trk *tr\n");
                   //sleep(2);

                printf("Woaaaah.....\n");
                // sleep(2);
                worldIntro.data[10][i] = ' ';
                worldIntro.data[10][i-1] = '.';
                  ispisIntro(&worldIntro);
                 //sleep(3);
                
                 break;
            }
            worldIntro.data[10][i-1] = '.';
            worldIntro.data[10][i] = '?';
             ispisIntro(&worldIntro);
             // sleep(1);
            
 
        }

      
        
        

      


}










