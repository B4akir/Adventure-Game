#include "big-m.h"





// aktivacija na slovo I
void checkInventory(Player *player,char unos) {
    

    do {
        system("cls");
        printf("Inventory: \n");

        for (int i = 0; i < 5; i++) {
            printf("| [%d] %s | \n", i, player->inventory.items[i]);
        }

        printf("Q je izlaz iz inventorya\n");
        printf("D je izbacivanje itema\n");
        unos = _getch();

        switch (unos) {
            case 'q':
                // Exit the inventory loop
                return;

            case 'd':
                printf("Unesite broj itema koji zelite da izbacite\n");
                int broj;
                scanf("%d", &broj);
              
                for (int i=0; i<5; i++){
                  
                  if (broj==i){

                        strcpy(player->inventory.items[broj], ".");
                  }


                      
                            
                           
                   
                }

            


        }
    } while (1); // Continue looping until the player exits the inventory
}





void initalPosition(Player *player, Region *region){ // pocetna pozicija playera

    Region *region0 = &regions[0]; // stavlja ga u regiju 0
    player->oldChar = '.'; // deklarise prvo proslo mjesto, kada se player pomjeri da ostane tacka 


    // stavlja pocetne kordinate playera
    player->position.y= region0->position.y+1;
    player->position.x= region0->position.x+2;
    player->karakter='W';
    player->inRegion=0; // stavlja ga u regiju 0

    }; 





void movement(Player *player, World *world, Region *region, char unos){ // player movement


        int newX, newY;

        world->data[player->position.y][player->position.x] = player->oldChar;   //uzima podatke na trenuntim kordinatama playera da ih poslije moze zamijeniti kada se player pomjeri
    

    // uzima input unosa, bez cekanja scanf-a. Brze je od scanf-a jer scanf uzima input tek kada se pritisne enter, a _getch uzima input odmah, te scanf koristi puno vise funkcija
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
        
        
       
         if ((newX==5 && newY==11)){
            printf("Troll: Stomp Stomp Stomp");
            sleep(1);
          
         }


        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            player->oldChar = world->data[newY][newX];


            // salje u player strukturu nove kordinate playera

            player->position.y = newY;
            player->position.x = newX;
          
        }



        // ako player zeli ici na poziciju trenutnog enemya, pokrece combatSistem. 

   
       else if (newArea == regions[player->inRegion].enemy.constKarakter) {


               initiateCombat(player, region);
               
        }

    else if (newArea=='A' || newArea=='D' || newArea=='H'){

        regions[player->inRegion].item.pickedUp=1;
        printf("Pokupio si: %c \n" , regions[player->inRegion].item.karakter);
        sleep (2);
            player->position.y = newY;
            player->position.x = newX;

        


 

    
int itemAssigned;

for (int i=0; i<5; i++){
    itemAssigned = 0;
    switch (regions[player->inRegion].item.karakter)
    {
        case 'A':
            for (int j=0; j<5; j++) {
                if (strcmp(player->inventory.items[j], ".") == 0) {
                    strcpy(player->inventory.items[j], "+Attack");
                    player->stats.attack=player->stats.attack+5;
                    itemAssigned = 1;
                    break;
                }
            }
            break;
        case 'D':
            for (int j=0; j<5; j++) {
                if (strcmp(player->inventory.items[j], ".") == 0) {
                    strcpy(player->inventory.items[j], "+Ukupan hp ");
                    player->stats.constHealth=player->stats.constHealth+5;
                    itemAssigned = 1;
                    break;
                }
            }
            break;
        case 'H':
            printf ("Potpuno si izljicen\n");
            player->stats.health= player->stats.constHealth;
            break;
    }
    if (itemAssigned) break;
}
    }
}
    // inicijalizira playera na mjesto deklarisano u funkciji movement
    void initPlayer(Player *player, World *world) {
    

    // postavlja world data na kordinatama playera u karakter koji je player izabro u funkciji kreator
        world->data[player->position.y][player->position.x] = player->karakter;
    }

// pocetna funkcija za deklarisanje imena playera i njegovog zeljenog znaka





void ime (Player *player){


    printf("Unesite vase ime:\n");
    scanf("%19s", player->ime);
     while (getchar() != '\n');

}



   void kreator (Player *player) {
   

    // ukloni buffer da ne zeza sa konzolom
   

    printf("Nalazis se u mracnoj prostoriji.\n Prepodstavljas da si pao kroz labavi saht neodgovornih radnika. ");
    printf("Ispred sebe vidis stari kostur, koji je vjerovatno pao prije tebe.\n");
    printf("Kostur u ruci drzi: \n1.Mac \n2.Magicni stap \n3.Luk i strijele\n");

    int odabir;
    printf("Unesite 1 2 ili 3\n");
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

