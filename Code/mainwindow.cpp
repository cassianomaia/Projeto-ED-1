#include <SFML/Graphics.hpp>
#include "Screens.hpp"


int main(){

    std::vector<cScreen*> Screens;
    int screen = 0;


    sf::RenderWindow Tela(sf::VideoMode(800, 600), "Pianus");
   
    menu s0;
    Screens.push_back(&s0);
//    jogo s1;
//    Screens.push_back(&s1);
//    about s2;
//    Screens.push_back(&s3);
//    howtoplay s3;

    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(Tela);
    }
    return 0;
}