#include "big-m.h"

void initalPosition(Player *player, Region *region){ // pocetna pozicija playera

    Region *region0 = &regions[0]; // stavlja ga u regiju 0
    player->oldChar = '.'; // deklarise prvo proslo mjesto, kada se player pomjeri da ostane tacka 


    // stavlja pocetne kordinate playera
    player->position.y= region0->position.y+1;
    player->position.x= region0->position.x+2;
    player->inRegion=0; // stavlja ga u regiju 0

    }; 





void movement(Player *player, World *world, Region *region){ // player movement


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



        if (newArea == '.' || newArea == '=' || newArea == VRATA) {  // ' ' je void, '=' je hodnjik, VRATA su vrata 
        
        


        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            player->oldChar = world->data[newY][newX];


            // salje u player strukturu nove kordinate playera

            player->position.y = newY;
            player->position.x = newX;
        }



        // ako player zeli ici na poziciju trenutnog enemya, pokrece combatSistem. 

       if (newArea == region->enemy.karakter) {
               initiateCombat(player, region);
        }


    
        
        //ceka 100ms
        Sleep(100);
    }

    // inicijalizira playera na mjesto deklarisano u funkciji movement
    void initPlayer(Player *player, World *world) {
    

    // postavlja world data na kordinatama playera u karakter koji je player izabro u funkciji kreator
        world->data[player->position.y][player->position.x] = player->karakter;
    }

// pocetna funkcija za deklarisanje imena playera i njegovog zeljenog znaka
   void kreator (Player *player) {
    printf("Unesite vase ime:\n");
    scanf("%19s", player->ime);

    // ukloni buffer da ne zeza sa konzolom
    while (getchar() != '\n');

    printf("Izaberite vasu klasu: \n");
    printf("1. Knight: W,  15 hp, 5 attack \n");
    printf("2. Mage:   M,  5 hp, 14 attack \n");
    printf("3. Archer: A,  10 hp, 10 attack \n");

    int odabir;
    printf("Unesite 1, 2, ili 3\n");
    scanf("%d", &odabir);

    while(odabir!=1 && odabir!=2 && odabir!=3){
        printf("Unesite 1,2, ili 3\n");
        scanf("%d", &odabir);
    }

    switch (odabir)
    {
        case 1:
            player->karakter = 'W';
            initalStatsPlayer(player,odabir);
            break;
        case 2:
            player->karakter = 'M';
            initalStatsPlayer(player,odabir);
            break;
        case 3:
            player->karakter = 'A';
            initalStatsPlayer(player,odabir);
            break;
    }
}


