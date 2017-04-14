#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int main(){
    sf::Window window(sf::VideoMode(800, 600), "Pianus");
    // Loop para deixar a janela aberta
    while (window.isOpen()){
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            switch (event.type){
                // Fecha a janela
                case sf::Event::Closed:
                    window.close();
                break;
                // key pressed
                case 

                break;
                
                default:

                break;
            }
        }
        window.open();

        window.display();
    }
    return 0;
}