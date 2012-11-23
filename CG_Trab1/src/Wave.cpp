#include "wave.h"

Wave::Wave()
{
    timer = 200;
    nivel = 1;
}

void Wave::update(Player &player){
    if(nivel== 1){
    for(i=0;i<NUM_ZUMBIS;i++){
        zumbis[i].nasce(player);
    }
    nivel=2;
    }
    for(i=0 ; i< (NUM_ZUMBIS) ; i++){
        if (zumbis[i].bodyBehavior() == Object::ACTIVE){
            zumbis[i].movimento(player);
        }
    }
}

Zumbi* Wave::getZumbis(){
    return zumbis;
}

void Wave::insertCenario(Scenario &cenario){
    int i;
    for(i=0;i<NUM_ZUMBIS;i++){
        zumbis[i].insertCenario(cenario);
    }
}
