#include <stdio.h>
#include <stdlib.h>



#define BIJELA 178




typedef struct {
    char data[50][50];
} World;

typedef struct {
    int startX, startY; // Switched startX and startY
    int width, height;
    char fillCharacter;
    int regionSize;
} Region;

void regionInit(Region *region, int startY, int startX, int height, int width, char fillCharacter) {
    region->startY = startY;
    region->startX = startX;
    region->height = height;
    region->width = width;
    region->fillCharacter = fillCharacter;
}







typedef struct {
    int x,y;

}Player;

typedef struct {
    char karakter;
    char ime[30];
} Character;


   Region regions[6];



void initWorld(World *world) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            world->data[i][j] = ' ';
        }
    }
}

void ispis(World *world) {
    system("cls");
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            printf("%c", world->data[i][j]);
        }
        printf("\n");
    }
}

void regionIntoWorld(Region *region, World *world) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if ((i >= region->startY && i <= region->startY + region->height) &&
                (j >= region->startX && j <= region->startX + region->width)) {
                // Check if on the edge
                if (i == region->startY || i == region->startY + region->height ||
                    j == region->startX || j == region->startX + region->width) {
                    world->data[i][j] = '+';


                    
                } 
                
                
                
                else {
                    world->data[i][j] = region->fillCharacter;
                }
           
               
            }
        }
    }
}





 

void doorL(Region *region, World *world,int index ){
    Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int height = region0->height;

 

 
        int i=y+height/2;


        world->data[i][x] = '#';



}

void doorR(Region *region, World *world, int index ){

   Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int height = region0->height;
    int width = region0->width;

 
        int i=y+height/2;
        int j=x+width;

        world->data[i][j] = '#';





}

void doorT(Region *region, World *world, int index){

   Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int width = region0->width;


 
    int j=x+width/2;


    world->data[y][j] = '#';



}

void doorB(Region *region, World *world, int index){

 Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int height = region0->height;
    int width = region0->width;
 

 
    int j=x+width/2;
    int i=y+height;

    world->data[i][j] = '#';



}


 





void initializeRegions(World *world) {
    regionInit(&regions[0], /* y*/1,   /* x*/ 0, /* height*/ 7,  /* width*/  10, '.');
    regionInit(&regions[1], 1, 30, 5, 12, '1');
    regionInit(&regions[2], 12, 1, 5, 15, '2');
    regionInit(&regions[3], 25, 5, 5, 10, '3');
    regionInit(&regions[4], 10, 30, 5, 10, '4');
    regionInit(&regions[5], 25, 30, 5, 5, '5');

    for (int i = 0; i < 6; i++) {
        regionIntoWorld(&regions[i], world);
    }
}


void initializeDoors(World *world, Region *region) {
    doorR(region, world, 0);


    doorL(region, world, 1);
    doorB(region, world, 1);

    doorT(region, world, 2);
    doorR(region, world, 2);

    doorT(region, world, 3);


    doorB(region, world, 4);
    doorT(region, world, 4);


    doorT(region, world, 5);
}








hodnjikH(int x, int y, int z , World *world){

//x je pocetak hodnika
//y je visina hodnjika
//z je intezitet hodnjika (duzina)

for (int i=0; i<50; i++){
    for (int j=0; j<50; j++){
       if (y==i && j>=x && j<=z+x){
           world->data[i][j]=BIJELA;
     
    

}
}
}
}



hodnjikV(int x, int y, int z , World *world){

//x je pocetak hodnika
//y je visina hodnjika
//z je intezitet hodnjika (duzina)

for (int i=0; i<50; i++){
    for (int j=0; j<50; j++){
       if (x==j && i>=y && i<=z+y){
           world->data[i][j]=BIJELA;
     
    

}
}
}
}











int main() {
    World world;
    Region region;
    Character karakter;
  


    initWorld(&world);
    initializeRegions(&world);
    initializeDoors(&world, &region);
    hodnjikH(11,4,17,&world);
    hodnjikH(11+16,3,2,&world);

    hodnjikV(36,7,2,&world);

    ispis(&world);
int x;




    scanf("%d",x);
   



    return 0;
}
