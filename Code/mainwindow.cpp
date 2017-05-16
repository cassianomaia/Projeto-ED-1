#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screens.hpp"

int main(){

    std::vector<cScreen*> Screens;
    int screen = 0;

    sf::RenderWindow Tela(sf::VideoMode(800, 600), "Pianus");
   
    menu s0;
    Screens.push_back(&s0);
    lv1 s1;
    Screens.push_back(&s1);
    lv2 s2;
    Screens.push_back(&s2);
    lv3 s3;
    Screens.push_back(&s3);

    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(Tela);
    }
    return 0;
}