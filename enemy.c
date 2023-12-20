#include "big-m.h"


void enemyInitialPos(Enemy *enemy, World *world, Region *region){

Region *region0= &regions[0];
    

    char names[2] = {'E', 'A'};

    //random number


        int random = rand()%4;
    // initial enemy position
    region0->enemy.position.x = region0->position.x + region0->width-random;
    region0->enemy.position.y = region0->position.y + region0->height-random;
    region0->enemy.karakter = names[random];
    region0->enemy.oldChar = '.';



}
void enemyLogic(Enemy *enemy, World *world, Region *region, int index){

    Region *region0= &regions[index];
    
    

    world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.oldChar;
    int direction = rand() % 4; // Generate a random number between 0 and 3
char newX, newY;
    switch (direction) {
        case 0: // Move up
             newY=region0->enemy.position.y-1;
             newX=region0->enemy.position.x;
            break;
        case 1: // Move down
             newY=region0->enemy.position.y+1;
            newX=region0->enemy.position.x;
            break;
        case 2: // Move left
             newX=region0->enemy.position.x-1;
              newY=region0->enemy.position.y;
            break;
        case 3: // Move right
            newX=region0->enemy.position.x+1;
            newY=region0->enemy.position.y;
            break;
    }
char newArea = world->data[newY][newX];  // deklarisemo newArea da bi mogli provjeriti da li je validno mjesto za pokretanje



        if (newArea == '.' || newArea == '=' || newArea == VRATA) {  // ' ' je void, '=' je hodnjik, VRATA su vrata :/
        
        

        region0->enemy.oldChar = world->data[newY][newX];
        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            // salje u player strukturu nove kordinate playera
            region0->enemy.position.y = newY;
            region0->enemy.position.x = newX;
        }
    

}


// enemy 
     void enemyInit(Enemy *enemy, World *world, Region *region) {

        Region *region0 = &regions[0];

     world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.oldChar;

    
        world->data[region0->enemy.position.y][region0->enemy.position.x] = region0->enemy.karakter;
    }