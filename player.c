#include "big-m.h"

void initalPosition(Player *player, Region *region){ // pocetna pozicija playera

    Region *region0 = &regions[0];
    player->oldChar = '.';
    player->position.y= region0->position.y+1;
    player->position.x= region0->position.x+2;


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



        if (newArea == '.' || newArea == '=' || newArea == VRATA) {  // ' ' je void, '=' je hodnjik, VRATA su vrata :/
        
        


        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            player->oldChar = world->data[newY][newX];
            // salje u player strukturu nove kordinate playera
            player->position.y = newY;
            player->position.x = newX;
        }


    else if ( newArea=='B'){

       initiateCombat(player, &region);


    }


    
        //make wait for 1 second
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

        printf("Kako zelite izgledati? \nUnesite bilo koji ASCII karakter:\n");
        scanf(" %c", &player->karakter);
    }




void playerHealth(Player *player){

    player->stats.health = 100;
    player->stats.attack = 10;


   }
