#ifndef PLAYER_H
#define PLAYER_H


typedef struct {
    int x,y;

}Player;


void initPlayer(Player *player);
void movement(Player *player);


#endif // PLAYER_H