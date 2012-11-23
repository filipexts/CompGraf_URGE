#ifndef WAVE_H
#define WAVE_H
#include "bibliotecas.h"
#include "Constantes.h"
#include "Zumbi.h"
#include "Player.h"
#include "time.h"
class Wave
{
    public:
        Wave();
        void update(Player &player);
        Zumbi* getZumbis();
        void insertCenario(Scenario &cenario);
        Zumbi zumbis[NUM_ZUMBIS];

    private:
        int i;
        int timer;
        int nivel;
};

#endif // WAVE_H
