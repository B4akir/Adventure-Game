#include "big-m.h"

//regije

    //deklarisanje reegije u zavisnosti od kordinata
    //prima kordinate od arraya Regions, koji u sebi sadrzi tip Region, koji dalje ima svoje kordinate velicinu...



    void regionIntoWorld2(Region *region, World *world2) {
        for (int i = 0; i < HEIGHT; i++) { // ide kroz citavu matricu world
            for (int j = 0; j < WIDTH; j++) {

                    // deklarise obim regije
                    
                if ((i >= region->position.y && i <= region->position.y + region->height) &&
                    (j >= region->position.x && j <= region->position.x + region->width)) {



                    // desni gronji cosak
                    if (i == region->position.y && j == region->position.x + region->width) {
                        world2->data[i][j] = DESNIG;
                    }
                    // lijevi gornji cosak
                    else if (i == region->position.y && j == region->position.x) {
                        world2->data[i][j] = LIJEVIG;
                    }
                    // desni donji cosak
                    else if (i == region->position.y + region->height && j == region->position.x + region->width) {
                        world2->data[i][j] = DESNID;
                    }
                    // lijevi donji cosak
                    else if (i == region->position.y + region->height && j == region->position.x) {
                        world2->data[i][j] = LIJEVID;
                    }
                    // vertikalni zid
                    else if ((j == region->position.x || j == region->position.x + region->width) && (i != region->position.y && i != region->position.y + region->height)) {
                        world2->data[i][j] = ZID;
                    }
                    // horizontalni zid
                    else if ((i == region->position.y || i == region->position.y + region->height) && (j != region->position.x && j != region->position.x + region->width)) {
                        world2->data[i][j] = PLAFON;
                    }
                    else {
                        //unutrasnjost regije 
                        world2->data[i][j] = region->fillCharacter;
                    }
                }
            }
        }
    }

    
    // samo salje dobijene podatke u strukturu regije
    void regionInit2(Region *region, int startY, int startX, int height, int width, char fillCharacter) {
        region->position.y = startY;
        region->position.x = startX;
        region->height = height;
        region->width = width;
        region->fillCharacter = fillCharacter;
    }




      void initializeRegions2(World *world2, RandomNumbers *numbers) {


      
    regionInit2(&regions[0], /* y*/1,   /* x*/ 1, /* height*/  numbers->br1,  /* width*/  numbers->br2, '.');
        
         
         regionInit2(&regions[1], /* y*/1,   /* x*/ 18, /* height*/ 7,  /* width*/  14, '.');

          
         regionInit2(&regions[2], /* y*/ 12,   /* x*/ 5, /* height*/ 4,  /* width*/  numbers->br3, '.');
         regionInit2(&regions[3], /* y*/ numbers->br4,   /* x*/ 37, /* height*/ 4,  /* width*/  15, '.');
         regionInit2(&regions[4], /* y*/ 1,   /* x*/62 , /* height*/ 13,  /* width*/  9, '.');


        for (int i = 0; i < 7; i++) {
            regionIntoWorld2(&regions[i], world2);
        }
    }


//doors i hodnjiks
    void doorL2(Region *region, World *world2,int index, int brVrata){
        Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;

    

    
            int i=y+height/2-1;

            
            world2->data[i][x] = VRATA;
            region0->doors[brVrata].y = i;
            region0->doors[brVrata].x = x;



    }

    void doorR2(Region *region, World *world2, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;
        int width = region0->width;

    
            int i=y+height/2;
            int j=x+width;

            world2->data[i][j] = VRATA;
            region0->doors[brVrata].y = i;
            region0->doors[brVrata].x = j;





    }

    void doorT2(Region *region, World *world2, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int width = region0->width;


    
        int j=x+width/2;


        world2->data[y][j] =VRATA;
        region0->doors[brVrata].y = y;
        region0->doors[brVrata].x = j;



    }

    void doorB2(Region *region, World *world2, int index, int brVrata ){

    Region *region0 = &regions[index];

        int y = region0->position.y;
        int x = region0->position.x;
        int height = region0->height;
        int width = region0->width;
    

    
        int j=x+width/2;
        int i=y+height;

        world2->data[i][j] = VRATA;
        region0->doors[brVrata].y = i;
        region0->doors[brVrata].x = j;



    }

    void initializeDoors2(World *world2, Region *region) {
        
        
        //regija 0
        
        doorR2(region, world2, 0, 2);
        doorB2(region, world2, 0, 3);



        //regija 1
        doorL2(region, world2, 1, 0);
        
        doorB2(region, world2, 1, 3);

        

         //regija 2
         
         doorT2(region, world2, 2, 1);
         doorR2(region, world2, 2, 2);
         doorL2(region, world2, 2, 0);



         //regija 3
         doorT2(region, world2, 2, 1);
         doorR2(region, world2, 3, 2);
         doorB2(region, world2, 3, 3);
        


         //regija 4
         doorL2(region, world2, 4, 0);
         


 


        
    



    }