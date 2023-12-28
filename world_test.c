

// pozovi sve potrebne funckije
    #include "big-m.h"

    #include "inventory.c"
    #include "intro.c"
    #include "regions_fake.c"
    #include "enemy.c"
    #include "regions.c"
    #include "player.c"
    #include "combat.c"

// stavi u matricu world prazna polja
    void initWorld(World *world) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
            
          
            world->data[i][j] = ' ';
            }
        }
    }

    




    // ispisi world. 
//oh yeah

    void ispis(World *world, Player *player, Region *region) {


// Ovo je samo za prvu regiju, treba napraviti za sve regije



// izbrise prosli ispis
    system("cls");

    // isprinta world
    char buffer[HEIGHT * (WIDTH + 1) + 1]; // +1 for each newline and +1 for null terminator
    char *p = buffer;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            *p++ = world->data[i][j];
        }
        *p++ = '\n';
    }
    *p = '\0'; // null terminate the string
    
    
    // ispise statse playera i enemya
    printf("%s", buffer);
    

    Region *region0=&regions[player->inRegion];
    printf (" Player health: %d(%d)       Player attack: %d\n", player->stats.health, player->stats.constHealth, player->stats.attack, player->stats.constAttack);
    printf("Sewage dwellers name: %s \n", player->ime);
    for (int i=0; i<5; i++){
  
        
    }
    

}














// stavi regiju na svijet

void putXOnEdges(World *world) {
    int rows = sizeof(world->data) / sizeof(world->data[0]);
    int cols = sizeof(world->data[0]) / sizeof(world->data[0][0]);

    // Put 'x' on the top and bottom edges
    for (int i = 0; i < cols; i++) {
        world->data[0][i] = 'x';
        world->data[rows - 1][i] = 'x';
    }

    // Put 'x' on the left and right edges
    for (int i = 0; i < rows; i++) {
        world->data[i][0] = 'x';
        world->data[i][cols - 1] = 'x';
    }
}


// spaja vrata regija

int connectDoors(World *world, int r1, int r2, int door1, int door2, World *world2)
{

    Region *region0 = &regions[r1];
    Region *region1 = &regions[r2];


  
    Position temp;
    Position end;
    Position previous;

    int count = 0;

    temp.x =region0->doors[door1].x;
    temp.y = region0->doors[door1].y;

    end.x= region1->doors[door2].x;
    end.y= region1->doors[door2].y;


    previous = temp;

    while (temp.x!= end.x || temp.y != end.y)
    {
        /* step left */
        if ((abs((temp.x - 1) - end.x) < abs(temp.x - end.x)) && (world2->data[temp.y][temp.x-1] == ' '))
        {
            previous.x = temp.x;
            temp.x = temp.x - 1;
               world->data[temp.y][temp.x] = '=';

        /* step right */
        } else if ((abs((temp.x + 1) - end.x) < abs(temp.x - end.x)) && (world2->data[temp.y][temp.x + 1] == ' '))
        {
            previous.x = temp.x;
            temp.x = temp.x + 1;
               world->data[temp.y][temp.x] = '=';
        /* step down */
        } else if ((abs((temp.y + 1) - end.y) < abs(temp.y - end.y)) && (world2->data[temp.y + 1][temp.x]  == ' '))
        {
            previous.y = temp.y;
            temp.y = temp.y + 1;
               world->data[temp.y][temp.x] = '=';
        /* step up */
        } else if ((abs((temp.y - 1) - end.y) < abs(temp.y - end.y)) && (world2->data[temp.y - 1][temp.x]  == ' '))
        {
            previous.y = temp.y;
            temp.y = temp.y - 1;
               world->data[temp.y][temp.x] = '=';
        } else
        {
            if (count == 0)
            {
                temp = previous;
                count++;
                continue;
            }
            else
            {
                return 0;
            }
        }

     


    }

    return 1;
}







   



















//make a function that determines if this position is in a region



 

   





int main (){







// deklaracija tipova i varijabli datih
World world;
Player player;
Region region;
Enemy enemy;
World world2;
RandomNumbers numbers;













intro(&player);

generateRandomNumbers(&numbers);


initWorld(&world2);
 









initializeRegions2(&world2, &numbers);
initializeDoors2(&world2, &region);








// pocetne inicijalizacije


system("cls");
kreator(&player);

system("cls");
printf("Pomjeranje je sa WASD. \n Inventory je sa I. \n");

initialInventory(&player);
initWorld(&world);
initializeRegions(&world, &player, &numbers, &world2);
putXOnEdges(&world);
putXOnEdges(&world2);


initalPosition(&player, &region);
enemyInit(&region, &world);
initalStatsEnemy(&region);

 isInRegion(&region, &player);

 initItems(&region);

itemsIntoWorld(&region, &world);

sleep(2);
int br=0;


while(1){


 
 

        populateWorldWithRegions(regions, 5, &world, &player, &region, &world2);
        enemySpawnActivation(&player, &region,&world);
        
        enemiesIntoWorld(&world, &region);

        if (br==0){
            initPlayer(&player,&world);
            ispis(&world, &player,&region);
        }






        char unos = _getch();

        if (unos=='i'){
        checkInventory(&player, unos);

        }
        else {
            
        movement(&player,&world, &region, unos);
        }
        spawnItem(&player,&region); //provjeri da li je player u regiji
        itemsIntoWorld(&region, &world);

        initPlayer(&player,&world);
        isInRegion(&region, &player);
        


        ispis(&world, &player,&region);
        if (br==2){
            printf("Moram izaci odavdje");
        }



        br++;
        if (player.stats.health<=0){
            printf("Umro si\n");
            break;
        }


}







}

