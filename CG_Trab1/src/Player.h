#ifndef PLAYER_H
#define PLAYER_H

#include "bibliotecas.h"
#include "Constantes.h"
#include <iostream>

class Player:public FirstPersonCamera
{
public:
    Player();
    void die();
    int collide(Object &other);
    int isDead();
    void update();
private:
    int life;
    Sound sfx;
};


#endif // PLAYER_H
