#include "Player.h"

Player::Player()
{

    activeBody();
    position(100,0,80);
    scale(1.0);
    changeKey("Forward", Input::Keyboard::UP);
    changeKey("Left", Input::Keyboard::LEFT);
    changeKey("Right", Input::Keyboard::RIGHT);
    changeKey("Back", Input::Keyboard::DOWN);

    label(LABEL_PLAYER);
    linearSpeed(2.0);

    //sfx.load("media/sfx/choir.wav");
    //sfx.play();

}

int Player::collide(Object &other)
{
    if (other.label() == LABEL_ZUMBI)
    {
        die();
    }
    return 1;
}

void Player::die(){
    control().disableAll();
    disableMouse();
}

void Player::update(){

};
int Player::isDead()
{
    if (life<=0)
        return 1;
    return 0;
}

