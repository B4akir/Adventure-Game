#ifndef PLAYER_H
#define PLAYER_H


typedef struct {
    int x,y;

}Player;



void movement(Player *player);
void initalPosition(Player *player);


#endif // PLAYER_H