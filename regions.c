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

    
    // samo salje dobijene podatke u strukturu regije
    void regionInit(Region *region, int startY, int startX, int height, int width, char fillCharacter) {
        region->position.y = startY;
        region->position.x = startX;
        region->height = height;
        region->width = width;
        region->fillCharacter = fillCharacter;
    }


      void initializeRegions(World *world, Player *player) {


        srand(time(0));
        int randomNumber = 5+rand()%10;

      
    

        switch ()

       regionInit(&regions[0], /* y*/1,   /* x*/ 1, /* height*/  3+rand()%(6-3),  /* width*/  4+rand()%(8-4), '.');
        regionInit(&regions[1], /* y*/1,   /* x*/ 18, /* height*/ 7,  /* width*/  14, '.');
        regionInit(&regions[2], /* y*/ 12,   /* x*/ 5, /* height*/ 4,  /* width*/  20+rand()%(30-20), '.');
        regionInit(&regions[3], /* y*/ 2+rand()%(9-2),   /* x*/ 37, /* height*/ 4,  /* width*/  15, '.');
        regionInit(&regions[4], /* y*/ 1,   /* x*/62 , /* height*/ 5+rand()%(15-5),  /* width*/  9, '.');


        for (int i = 0; i < 7; i++) {
            regionIntoWorld(&regions[i], world);
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
        region0->doors[brVrata].y = i;
        region0->doors[brVrata].x = j;



    }

    void initializeDoors(World *world, Region *region) {
        
        
        //regija 0
        
        doorR(region, world, 0, 2);
        doorB(region, world, 0, 3);



        //regija 1
        doorL(region, world, 1, 0);
        
        doorB(region, world, 1, 3);

        

         //regija 2
         
         doorT(region, world, 2, 1);
         doorR(region, world, 2, 2);


         //regija 3
         doorT(region, world, 2, 1);
         doorR(region, world, 3, 2);
         doorB(region, world, 3, 3);
        


         //regija 4
         doorL(region, world, 4, 0);
         


 


           //regija 1



           //regija 2


           //regija 3

           //regija 4
        
    



    }