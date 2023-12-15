#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


#define HODNJIK 34
#define VRATA 15
#define ZID 186
#define PLAFON 205

#define LIJEVIG 201
#define DESNIG 187
#define LIJEVID 200
#define DESNID 188




#define HEIGHT 40
#define WIDTH 134


typedef struct {
    char data[HEIGHT][WIDTH];
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







   Region regions[8];



void initWorld(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            if (i==HEIGHT-1 && j==WIDTH-1){
                world->data[i][j] = 'X';
            }

            else if (i==0 && j==0){
                world->data[i][j] = 'X';
            }
           else  if (i==0 && j==WIDTH-1){
                world->data[i][j] = 'X';
            }
           else  if (i==HEIGHT-1 && j==0){
                world->data[i][j] = 'X';
            }
            else{
                world->data[i][j] = ' ';
            }
       
        }
    }
}

void ispis(World *world) {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", world->data[i][j]);
        }
        printf("\n");
    }
}

void regionIntoWorld(Region *region, World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if ((i >= region->startY && i <= region->startY + region->height) &&
                (j >= region->startX && j <= region->startX + region->width)) {
                // Check if on the right upper edge
                if (i == region->startY && j == region->startX + region->width) {
                    world->data[i][j] = DESNIG;
                }
                // Check if on the left upper edge
                else if (i == region->startY && j == region->startX) {
                    world->data[i][j] = LIJEVIG;
                }
                // Check if on the bottom right edge
                else if (i == region->startY + region->height && j == region->startX + region->width) {
                    world->data[i][j] = DESNID;
                }
                // Check if on the bottom left edge
                else if (i == region->startY + region->height && j == region->startX) {
                    world->data[i][j] = LIJEVID;
                }
                // Check if on the vertical lines not containing edges
                else if ((j == region->startX || j == region->startX + region->width) && (i != region->startY && i != region->startY + region->height)) {
                    world->data[i][j] = ZID;
                }
                // Check if on the horizontal lines not containing edges
                else if ((i == region->startY || i == region->startY + region->height) && (j != region->startX && j != region->startX + region->width)) {
                    world->data[i][j] = PLAFON;
                }
                else {
                    world->data[i][j] = region->fillCharacter;
                }
            }
        }
    }
}





 

void doorL(Region *region, World *world,int index){
    Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int height = region0->height;

 

 
        int i=y+height/2;

        
        world->data[i][x] = VRATA;



}

void doorR(Region *region, World *world, int index ){

   Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int height = region0->height;
    int width = region0->width;

 
        int i=y+height/2;
        int j=x+width;

        world->data[i][j] = VRATA;





}

void doorT(Region *region, World *world, int index){

   Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int width = region0->width;


 
    int j=x+width/2;


    world->data[y][j] = VRATA;



}

void doorB(Region *region, World *world, int index){

 Region *region0 = &regions[index];

    int y = region0->startY;
    int x = region0->startX;
    int height = region0->height;
    int width = region0->width;
 

 
    int j=x+width/2;
    int i=y+height;

    world->data[i][j] = VRATA;



}


//  #define HEIGHT 40
// #define WIDTH 134




void initializeRegions(World *world) {
    regionInit(&regions[0], /* y*/30,   /* x*/ 60, /* height*/ 7,  /* width*/  21, '.');
     regionInit(&regions[1], 30, 89, 5, 12, '1');
     regionInit(&regions[2], 22, 90, 4, 20, '2');
     regionInit(&regions[3], 22, 50, 4, 25, '3');
     regionInit(&regions[4], 18, 17, 4, 8, '4');
     regionInit(&regions[5], 25, 8, 5, 15, '5');
     regionInit(&regions[6], 33, 12, 5, 5, '6');
   

    for (int i = 0; i < 7; i++) {
        regionIntoWorld(&regions[i], world);
    }
}


void initializeDoors(World *world, Region *region) {
    
    
    //regija 0
    doorR(region, world, 0);
    doorL(region, world, 0);


// regija 1
    doorL(region, world, 1);
    doorT(region, world, 1);

//regija 2
    doorB(region, world, 2);
    doorL(region, world, 2);


//regija 3
doorR(region, world, 3);
doorT(region, world, 3);
doorL(region, world, 3);



//regija 4
    doorR(region, world, 4);
    doorB(region, world, 4);


//regija 5
doorT(region, world, 5);
doorB(region, world, 5);


//regia 6
doorT(region, world, 6);


}








hodnjikH(int x, int y, int z , World *world){

//x je pocetak hodnika
//y je visina hodnjika
//z je intezitet hodnjika (duzina)

for (int i=0; i<HEIGHT; i++){
    for (int j=0; j<WIDTH; j++){
       if (y==i && j>=x && j<=z+x){
           world->data[i][j]=HODNJIK;
     
    

}
}
}
}



hodnjikV(int x, int y, int z , World *world){

//x je pocetak hodnika
//y je visina hodnjika
//z je intezitet hodnjika (duzina)

for (int i=0; i<HEIGHT; i++){
    for (int j=0; j<WIDTH; j++){
       if (x==j && i>=y && i<=z+y){
           world->data[i][j]=HODNJIK;
     
    

}
}
}
}




hodnjikInit(World *world){
    // hodnjikH(11,4,17,world);
    // hodnjikH(11+16,3,2,world);

    // hodnjikV(36,7,2,world);
    



}






int main() {
    World world;
    Region region;
    Character karakter;



    initWorld(&world);
    initializeRegions(&world);
    initializeDoors(&world, &region);
    hodnjikInit(&world);

 

    ispis(&world);
int x;




    scanf("%d",&x);
   



    return 0;
}
