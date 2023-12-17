

//includes i defines
    #include <stdio.h>
    #include <stdlib.h>
    #include <Windows.h>
    #include <conio.h>
    #define HODNJIK 176
    #define VRATA 15
    #define ZID 186
    #define PLAFON 205
    #define LIJEVIG 201
    #define DESNIG 187
    #define LIJEVID 200
    #define DESNID 188
    #define HEIGHT 18
    #define WIDTH 80


typedef struct{
    int x,y;
}Position; 


typedef struct{
    Position position;
    char karakter;
    char oldChar;

} Enemy;



// Strukture i tipovi


    typedef struct {
    Position position;
    char karakter;
    char oldChar;
    char ime[20];

        }Player;


    typedef struct {
        char data[HEIGHT][WIDTH];
            } World;



        // krene od tacke x i y te se siri prema desno. 
        typedef struct {
            Position position; 
            int width, height;
            char fillCharacter;
            int regionSize;
            Position doors[4];


                } Region;

        // array regija
            Region regions[8];



// world 
    void initWorld(World *world) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
            
          
            world->data[i][j] = ' ';
            }
        }
    }




    // ispisuje world
    void ispis(World *world) {
        system("cls");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", world->data[i][j]);
            }
            printf("\n");
        }
    }







//player funkcije

    void initalPosition(Player *player){ // pocetna pozicija playera

    player->oldChar = '.';
    player->position.y= 4;
    player->position.x= 7;


    }; 




    // ceka da player unese w a s d, 
    // 

    void movement(Player *player, World *world){ // player movement


        int newX, newY;

        world->data[player->position.y][player->position.x] = player->oldChar;   //uzima podatke na trenuntim kordinatama playera da ih poslije moze zamijeniti kada se player pomjeri
    

    char unos = _getch(); // uzima input unosa, bez cekanja scanf-a. Brze je od scanf-a jer scanf uzima input tek kada se pritisne enter, a _getch uzima input odmah, te scanf koristi puno vise funkcija
    //kao npr strlen (Vidio na ranodm youtube videu o gta 5 optimiziaciji loading online ).


        // kalulise nove kordinate na osnovu unosa, pri tome deklarise u newY i newX; lokalne varijable.
        switch (unos){
            case 'w':
                newY = player->position.y - 1;
                newX = player->position.x;


                
                break;
            case 's':
                newY = player->position.y + 1;
                newX = player->position.x;


            
                break;
            case 'd':
                newX = player->position.x + 1;
                newY = player->position.y;

                break;
            case 'a':
                newX = player->position.x - 1;
                newY = player->position.y;

            
                break;
            default:
                return; // nemoj raditi nista, invalid input
        }

        //provjeri da li nove kordinate su validno mjesto za pokretanje
        // ovo ne da playeru da ulazi u zidove ili u void


        char newArea = world->data[newY][newX];  // deklarisemo newArea da bi mogli provjeriti da li je validno mjesto za pokretanje



        if (newArea == '.' || newArea == '=' || newArea == VRATA) {  // ' ' je void, '=' je hodnjik, VRATA su vrata :/
        
        


        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            player->oldChar = world->data[newY][newX];
            // salje u player strukturu nove kordinate playera
            player->position.y = newY;
            player->position.x = newX;
        }
    }

    // inicijalizira playera na mjesto deklarisano u funkciji movement
    void initPlayer(Player *player, World *world) {
    

    // postavlja world data na kordinatama playera u karakter koji je player izabro u funkciji kreator
        world->data[player->position.y][player->position.x] = player->karakter;
    }


//karakter funkcije


    // pocetna funkcija za deklarisanje imena playera i njegovog zeljenog znaka
    void kreator(Player *player) {
        printf("Unesite vase ime:\n");
        scanf("%19s", player->ime);

        // ukloni buffer da ne zeza sa konzolom
        while (getchar() != '\n');

        printf("Kako zelite izgledati? \nUnesite bilo koji ASCII karakter:\n");
        scanf(" %c", &player->karakter);
    }








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







    // salje regije preko regioninit, region arraya, region tipa i regionIntoWorld u world matrix

    void initializeRegions(World *world) {
        regionInit(&regions[0], /* y*/3,   /* x*/ 6, /* height*/ 5,  /* width*/  7, '.');
        // regionInit(&regions[1], 3, 9, 2, 4, '1');
        // regionInit(&regions[2], 2, 9, 2, 6, '2');
        // regionInit(&regions[3], 2, 5, 2, 8, '3');
        // regionInit(&regions[4], 1, 1, 2, 2, '4');
        // regionInit(&regions[5], 2, 0, 2, 5, '5');
        // regionInit(&regions[6], 3, 1, 2, 1, '6');

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

    

    
            int i=y+height/2;

            
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


        world->data[y][j] = VRATA;
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
        
        doorR(region, world, 0, 0);
         doorL(region, world, 0, 1);
          doorB(region, world, 0, 2);
           doorT(region, world, 0, 3);

    Region *region0 = &regions[0];
           for(int i=0; i<4; i++){

            printf("%d %d\n", region0->doors[i].y, region0->doors[i].x);
           }
        
    



    }








    void hodnjikH(int x, int y, int z , World *world){

    //x je pocetak hodnika
    //y je visina hodnjika
    //z je intezitet hodnjika (duzina)

    for (int i=0; i<HEIGHT; i++){
        for (int j=0; j<WIDTH; j++){
        if (y==i && j>=x && j<=z+x){
            world->data[i][j]='=';
        
        

    }
    }
    }
    }



    void hodnjikV(int x, int y, int z , World *world){

    //x je pocetak hodnika
    //y je visina hodnjika
    //z je intezitet hodnjika (duzina)

    for (int i=0; i<HEIGHT; i++){
        for (int j=0; j<WIDTH; j++){
        if (x==j && i>=y && i<=z+y){
            world->data[i][j]='=';
        
        

    }
    }
    }
    }


    void hodnjikInit(World *world){

    //x,y,z

    
    

    }



void initialEnemy (Enemy *enemy){
    enemy->position.x = 7;
    enemy->position.y = 7;
    enemy->karakter = 'E';
    enemy->oldChar = '.';
}

void enemyLogic(Enemy *enemy, World *world){

    world->data[enemy->position.y][enemy->position.x] = enemy->oldChar;
    int direction = rand() % 4; // Generate a random number between 0 and 3
char newX, newY;
    switch (direction) {
        case 0: // Move up
             newY=enemy->position.y-1;
             newX=enemy->position.x;
            break;
        case 1: // Move down
             newY=enemy->position.y+1;
            newX=enemy->position.x;
            break;
        case 2: // Move left
             newX=enemy->position.x-1;
              newY=enemy->position.y;
            break;
        case 3: // Move right
            newX=enemy->position.x+1;
            newY=enemy->position.y;
            break;
    }
char newArea = world->data[newY][newX];  // deklarisemo newArea da bi mogli provjeriti da li je validno mjesto za pokretanje



        if (newArea == '.' || newArea == '=' || newArea == VRATA) {  // ' ' je void, '=' je hodnjik, VRATA su vrata :/
        
        


        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            // salje u player strukturu nove kordinate playera
            enemy->position.y = newY;
            enemy->position.x = newX;
        }
    

}


// enemy 
     void enemyInit(Enemy *enemy, World *world) {
     world->data[enemy->position.y][enemy->position.x] = enemy->oldChar;

    
        world->data[enemy->position.y][enemy->position.x] = enemy->karakter;
    }





int main (){

// deklaracija tipova i varijabli datih
World world;
Player player;
Region region;
Enemy enemy;







// pocetne inicijalizacije
kreator(&player);
initalPosition(&player);
initWorld(&world);
initializeRegions(&world);
initializeDoors(&world, &region);
hodnjikInit(&world);
initialEnemy(&enemy);
enemyInit(&enemy, &world); 

//movement i ispis
while(1){

movement(&player,&world);
initPlayer(&player,&world);
enemyLogic(&enemy, &world);
enemyInit(&enemy, &world);

ispis(&world);




}







}

