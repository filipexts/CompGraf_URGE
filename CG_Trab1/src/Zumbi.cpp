#include "Zumbi.h"

Zumbi::Zumbi(){
    life = 100;
    label(LABEL_ZUMBI);
    load("media/models/Knight/knight.md2");
    changeAnimation(Animation::WALK);
    graphic().setAnimationDelay(Animation::WALK,8);
    graphic().setAnimationDelay(Animation::TAUNT02,3);
    graphic().setAnimationDelay(Animation::HIT01,6);
    graphic().setAnimationDelay(Animation::DIE01,6);
    changeBoundingVolume(Solid::OBOX);
    animatedVolume();
    inactiveBody();
    visible(false);
    //scale(0.5);
    position(0.0,20.0,0.0);
}

int Zumbi::collide(Object &other)
{
    if (other.label() == LABEL_MUNICAO)
    {
        visible(false);
        inactiveBody();
    }
    return 1;
}

void Zumbi::insertCenario(Scenario &cenario){
    cenario.insert(*this);
}

void Zumbi::nasce(Player &player){
    position(setPos(player));
    activeBody();
    visible(true);
}

Array Zumbi::setPos(Player &player){
    Array pos;
    float rand,x,y,z;
    do{
        rand = random()*255;
        x = rand - (255/2);
        rand = random()*255;
        z = rand - (255/2);
        y = 20;
        pos.set(x,y,z);
        if ( player.position().dist(pos) > 30.0){
        return pos;
        }
    }while(true);
}

void Zumbi::movimento(Player &player){
    if ((player.position() - position()).length() < 5.0)
    {
        if (graphic().getCurrentAnimation() != Animation::TAUNT02)
        {
            //Força colisão repetida de ataque
            Array tmp = (player.position() - position()).normalize()*200.0;
            tmp += Array(0,1000.0,0);
            body().force += tmp;
            tempAnimation(Animation::TAUNT02, Animation::WALK);
        }
    }
    else
    {
        body().force += (player.position() - position()).normalize()* VELOCIDADE_ZUMBI;
        direction(body().force);
    }
}
