#include "big-m.h"

//regije

    //deklarisanje reegije u zavisnosti od kordinata
    //prima kordinate od arraya Regions, koji u sebi sadrzi tip Region, koji dalje ima svoje kordinate velicinu...



    void regionIntoWorld(Region *region, World *world) {
        for (int i = 0; i < HEIGHT; i++) { // ide kroz citavu matricu world
            for (int j = 0; j < WIDTH; j++) {

                    // deklarise obim regije
                    
                if ((i >= region->position.y && i <= region->position.y + region->height) &&
                    (j >= region->position.x && j <= region->position.x + region->width)) {



                    // desni gronji cosak
                    if (i == region->position.y && j == region->position.x + region->width) {
                        world->data[i][j] = DESNIG;
                    }
                    // lijevi gornji cosak
                    else if (i == region->position.y && j == region->position.x) {
                        world->data[i][j] = LIJEVIG;
                    }
                    // desni donji cosak
                    else if (i == region->position.y + region->height && j == region->position.x + region->width) {
                        world->data[i][j] = DESNID;
                    }
                    // lijevi donji cosak
                    else if (i == region->position.y + region->height && j == region->position.x) {
                        world->data[i][j] = LIJEVID;
                    }
                    // vertikalni zid
                    else if ((j == region->position.x || j == region->position.x + region->width) && (i != region->position.y && i != region->position.y + region->height)) {
                        world->data[i][j] = ZID;
                    }
                    // horizontalni zid
                    else if ((i == region->position.y || i == region->position.y + region->height) && (j != region->position.x && j != region->position.x + region->width)) {
                        world->data[i][j] = PLAFON;
                    }
                    else {
                        //unutrasnjost regije 
                        world->data[i][j] = region->fillCharacter;
                    }
                }
            }
        }
    }






    


  
  


//doors i hodnjiks
    void doorL(Region *region, World *world,int index, int brVrata){
        Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;

    

    
            int i=y+height/2-1;
            
            
            world->data[i][x] = VRATA;

      


    }

  void doorLcord(Region *region, World *world,int index, int brVrata){
        Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;
        int i=y+height/2-1;

        region0->doors[brVrata].y = i;
        region0->doors[brVrata].x = x;



    }


  





    void doorR(Region *region, World *world, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;
        int width = region0->width;

    
            int i=y+height/2;
            int j=x+width;

            world->data[i][j] = VRATA;
           





    } 

 void doorRcord(Region *region, World *world, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;
        int width = region0->width;

    
            int i=y+height/2;
            int j=x+width;

       
            region0->doors[brVrata].y = i;
            region0->doors[brVrata].x = j;





    } 






    void doorT(Region *region, World *world, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int width = region0->width;


    
        int j=x+width/2;


        world->data[y][j] =VRATA;
      



    }

     void doorTcord(Region *region, World *world, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int width = region0->width;


    
        int j=x+width/2;


        
        region0->doors[brVrata].y = y;
        region0->doors[brVrata].x = j;



    }





    void doorB(Region *region, World *world, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;
        int width = region0->width;
    

    
        int j=x+width/2;
        int i=y+height;

        world->data[i][j] = VRATA;
      



    }



    void doorBcord(Region *region, World *world, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;
        int width = region0->width;
    

    
        int j=x+width/2;
        int i=y+height;

       
        region0->doors[brVrata].y = i;
        region0->doors[brVrata].x = j;



    }




 


   void populateWorldWithRegions(Region regions[], int regionCount, World *world, Player *player, Region *region, World *world2) {
    for (int i = 1; i < regionCount; i++) {
        if (player->inRegion==i && regions[i].populated==0){
            regionIntoWorld(&regions[i], world);
            regions[i].populated=1;

            switch (i){
                case 1:
                  doorL(&regions[i], world, 1, 0);
                  doorB(&regions[i], world, 1, 3);
                    connectDoors(world, 1, 2, 3, 1, world2);




                  break;


                case 2:
                    doorT(&regions[i], world, 2, 1);
                    doorR(&regions[i], world, 2, 2);
                    doorL(&regions[i], world, 2, 0);
                    world->data[regions[i].doors[0].y][regions[i].doors[0].x-1] = '#';
                    world->data[regions[i].doors[0].y-1][regions[i].doors[0].x-1] = '%';
                     world->data[regions[i].doors[0].y-2][regions[i].doors[0].x-1] = '&';
                    connectDoors(world, 2, 3, 2, 3, world2);
                    break;

                case 3:
                    doorT(&regions[i], world, 2, 1);
                    doorR(&regions[i], world, 3, 2);
                    doorB(&regions[i], world, 3, 3);
                    
                    connectDoors(world, 3, 4, 2, 0, world2); 
                    break;

                 case 4:
                      doorL(&regions[i], world, 4, 0);
                      
                      break;
            }

        


        }
    }
}







    
    // samo salje dobijene podatke u strukturu regije
    void regionInit(Region *region, int startY, int startX, int height, int width, char fillCharacter) {
        region->position.y = startY;
        region->position.x = startX;
        region->height = height;
        region->width = width;
        region->fillCharacter = fillCharacter;
    }



 void generateRandomNumbers(RandomNumbers *numbers) {
    srand(time(0));

    numbers->br1 = 3 + rand() % (6 - 3);
    numbers->br2 = 4 + rand() % (8 - 4);
    numbers->br3 = 20 + rand() % (30 - 20);
    numbers->br4 = 2 + rand() % (9 - 2);
    numbers->br5 = 5 + rand() % (15 - 5);
 
}



      void initializeRegions(World *world, Player *player, RandomNumbers *numbers, World *world2) {


     

        


       

            regions[0].populated=1;
            
             regionInit(&regions[0], /* y*/1,   /* x*/ 1, /* height*/  numbers->br1,  /* width*/  numbers->br2, '.');
            regionIntoWorld(&regions[0], world);
             doorR(&regions[0], world, 0, 2);
            doorB(&regions[0], world, 0, 3);
         
          



           
         regionInit(&regions[1], /* y*/1,   /* x*/ 18, /* height*/ 7,  /* width*/  14, '.');

          
         regionInit(&regions[2], /* y*/ 12,   /* x*/ 5, /* height*/ 4,  /* width*/  numbers->br3, '.');
         regionInit(&regions[3], /* y*/ numbers->br4,   /* x*/ 37, /* height*/ 4,  /* width*/  15, '.');
         regionInit(&regions[4], /* y*/ 1,   /* x*/62 , /* height*/ 13,  /* width*/  9, '.');



//region0

            doorRcord(&regions[0], world, 0, 2);
            doorBcord(&regions[0], world, 0, 3);

 
        // region 1
          doorLcord(&regions[1], world, 1, 0);
          doorBcord(&regions[1], world, 1, 3);


        //region 2
        doorTcord(&regions[2], world, 2, 1);
        doorRcord(&regions[2], world, 2, 2);
        doorLcord(&regions[2], world, 2, 0);




        //region3 
                doorTcord(&regions[3], world, 2, 1);
                 doorRcord(&regions[3], world, 3, 2);
                 doorBcord(&regions[3], world, 3, 3);



    //region 4
     doorLcord(&regions[4], world, 4, 0);



         connectDoors(world, 0, 1, 2, 0, world2);
         connectDoors(world, 0, 2, 3, 1, world2);
         connectDoors(world, 0, 2, 3, 0, world2);
            
    }



    void initItems(Region *region){


        for (int i=0; i<4; i++){

            Region *region0= &regions[i];

            char myCharArray[] = {'A', 'D', 'H'};  // attack . defense . health  

            int r = rand() % 3;
            region0->item.karakter=myCharArray[r];
            region0->item.position.x=region0->position.x+1;
            region0->item.position.y=region0->position.y+1; 
            region0->item.pickedUp=0;
            region0->item.activated=0;

        }
        




    }


void itemsIntoWorld(Region *region, World *world){

    for (int i=0;i<4; i++){

        
            Region *region0= &regions[i];
            if (region0->item.activated==1 && region0->item.pickedUp==0){
                  world->data[region0->item.position.y][region0->item.position.x] = region0->item.karakter;
    }
    else if  (region0->item.activated==0 && region0->populated==1){

        world->data[region0->item.position.y][region0->item.position.x] = '.';
    }

    else if (region0->item.activated==0 && region0->populated==0){
world->data[region0->item.position.y][region0->item.position.x] = ' ';

    }

else if (region0->item.pickedUp==1){
world->data[region0->item.position.y][region0->item.position.x] = '.';

    }


   

}


}

void spawnItem(Player *player, Region *region){


    for (int i=0;i<4;i++){

        Region *region0= &regions[i];   

    
    
        if (player->inRegion==i){

            region0->item.activated=1;




        }

        else {
            region0->item.activated=0;
        }
        


    }
    


}









