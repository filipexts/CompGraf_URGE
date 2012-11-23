#ifndef ZUMBI_H
#define ZUMBI_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "Player.h"

class Zumbi:public Generic
{
public:
    Zumbi();
    int collide(Object &other);
    void update();
    void insertCenario(Scenario &cenario);
    Array setPos(Player &player);
    void nasce(Player &player);
    void movimento(Player &player){
private:
    int life;
    float velocidade;
};

#endif // ZUMBI_H
