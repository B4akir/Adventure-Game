

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
    char karakter;

} Enemy;



// Strukture i tipovi


    typedef struct {
    int x,y;
    char prevCell;

        }Player;


    typedef struct {
    char oldChar;
        }oldChar;

    typedef struct {
    char karakter;
    char ime[20];
        } Character;

    typedef struct {
        char data[HEIGHT][WIDTH];
            } World;



        // krene od tacke x i y te se siri prema desno. 
        typedef struct {
            int startX, startY; // Switched startX and startY
            int width, height;
            char fillCharacter;
            int regionSize;
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

    void initalPosition(Player *player, oldChar *oldchar){ // pocetna pozicija playera

    oldchar->oldChar = '.';
    player->y= 4;
    player->x= 7;


    }; 




    // ceka da player unese w a s d, 
    // 

    void movement(Player *player, World *world, oldChar *oldchar){ // player movement


        int newX, newY;

        world->data[player->y][player->x] = oldchar->oldChar;   //uzima podatke na trenuntim kordinatama playera da ih poslije moze zamijeniti kada se player pomjeri
    

    char unos = _getch(); // uzima input unosa, bez cekanja scanf-a. Brze je od scanf-a jer scanf uzima input tek kada se pritisne enter, a _getch uzima input odmah, te scanf koristi puno vise funkcija
    //kao npr strlen (Vidio na ranodm youtube videu o gta 5 optimiziaciji loading online ).


        // kalulise nove kordinate na osnovu unosa, pri tome deklarise u newY i newX; lokalne varijable.
        switch (unos){
            case 'w':
                newY = player->y - 1;
                newX = player->x;


                
                break;
            case 's':
                newY = player->y + 1;
                newX = player->x;


            
                break;
            case 'd':
                newX = player->x + 1;
                newY = player->y;

                break;
            case 'a':
                newX = player->x - 1;
                newY = player->y;

            
                break;
            default:
                return; // nemoj raditi nista, invalid input
        }

        //provjeri da li nove kordinate su validno mjesto za pokretanje
        // ovo ne da playeru da ulazi u zidove ili u void


        char newArea = world->data[newY][newX];  // deklarisemo newArea da bi mogli provjeriti da li je validno mjesto za pokretanje



        if (newArea == '.' || newArea == '=' || newArea == VRATA) {  // ' ' je void, '=' je hodnjik, VRATA su vrata :/
        
        


        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            oldchar->oldChar = world->data[newY][newX];
            // salje u player strukturu nove kordinate playera
            player->y = newY;
            player->x = newX;
        }
    }

    // inicijalizira playera na mjesto deklarisano u funkciji movement
    void initPlayer(Player *player, World *world, Character *karakter) {
    

    // postavlja world data na kordinatama playera u karakter koji je player izabro u funkciji kreator
        world->data[player->y][player->x] = karakter->karakter;
    }


//karakter funkcije


    // pocetna funkcija za deklarisanje imena playera i njegovog zeljenog znaka
    void kreator(Character *karakter) {
        printf("Unesite vase ime:\n");
        scanf("%19s", karakter->ime);

        // ukloni buffer da ne zeza sa konzolom
        while (getchar() != '\n');

        printf("Kako zelite izgledati? \nUnesite bilo koji ASCII karakter:\n");
        scanf(" %c", &karakter->karakter);
    }








//regije

    //deklarisanje reegije u zavisnosti od kordinata
    //prima kordinate od arraya Regions, koji u sebi sadrzi tip Region, koji dalje ima svoje kordinate velicinu...



    void regionIntoWorld(Region *region, World *world) {
        for (int i = 0; i < HEIGHT; i++) { // ide kroz citavu matricu world
            for (int j = 0; j < WIDTH; j++) {

                    // deklarise obim regije
                    
                if ((i >= region->startY && i <= region->startY + region->height) &&
                    (j >= region->startX && j <= region->startX + region->width)) {



                    // desni gronji cosak
                    if (i == region->startY && j == region->startX + region->width) {
                        world->data[i][j] = DESNIG;
                    }
                    // lijevi gornji cosak
                    else if (i == region->startY && j == region->startX) {
                        world->data[i][j] = LIJEVIG;
                    }
                    // desni donji cosak
                    else if (i == region->startY + region->height && j == region->startX + region->width) {
                        world->data[i][j] = DESNID;
                    }
                    // lijevi donji cosak
                    else if (i == region->startY + region->height && j == region->startX) {
                        world->data[i][j] = LIJEVID;
                    }
                    // vertikalni zid
                    else if ((j == region->startX || j == region->startX + region->width) && (i != region->startY && i != region->startY + region->height)) {
                        world->data[i][j] = ZID;
                    }
                    // horizontalni zid
                    else if ((i == region->startY || i == region->startY + region->height) && (j != region->startX && j != region->startX + region->width)) {
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
        region->startY = startY;
        region->startX = startX;
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

    void initializeDoors(World *world, Region *region) {
        
        
        //regija 0
        doorR(region, world, 0);
    



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
    enemy->x = 7;
    enemy->y = 7;
    enemy->karakter = 'E';
}

void enemyLogic(Enemy *enemy, World *world, oldChar *oldchar){

    world->data[enemy->y][enemy->x] = oldchar->oldChar;
    int direction = rand() % 4; // Generate a random number between 0 and 3
char newX, newY;
    switch (direction) {
        case 0: // Move up
             newY=enemy->y-1;
             newX=enemy->x;
            break;
        case 1: // Move down
             newY=enemy->y+1;
            newX=enemy->x;
            break;
        case 2: // Move left
             newX=enemy->x-1;
              newY=enemy->y;
            break;
        case 3: // Move right
            newX=enemy->x+1;
            newY=enemy->y;
            break;
    }
char newArea = world->data[newY][newX];  // deklarisemo newArea da bi mogli provjeriti da li je validno mjesto za pokretanje



        if (newArea == '.' || newArea == '=' || newArea == VRATA) {  // ' ' je void, '=' je hodnjik, VRATA su vrata :/
        
        


        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            // salje u player strukturu nove kordinate playera
            enemy->y = newY;
            enemy->x = newX;
        }
    

}


// enemy 
     void enemyInit(Enemy *enemy, World *world, oldChar *oldchar) {
     world->data[enemy->y][enemy->x] = oldchar->oldChar;

    
        world->data[enemy->y][enemy->x] = enemy->karakter;
    }





int main (){

// deklaracija tipova i varijabli datih
World world;
Character karakter;
Player player;
Region region;
oldChar oldchar;
Enemy enemy;







// pocetne inicijalizacije
kreator(&karakter);
initalPosition(&player,&oldchar);
initWorld(&world);
initializeRegions(&world);
initializeDoors(&world, &region);
hodnjikInit(&world);
initialEnemy(&enemy);
enemyInit(&enemy, &world, &oldchar); 

//movement i ispis
while(1){

movement(&player,&world,&oldchar);
initPlayer(&player,&world,&karakter);
enemyLogic(&enemy, &world, &oldchar);
enemyInit(&enemy, &world, &oldchar);

ispis(&world);




}







}

