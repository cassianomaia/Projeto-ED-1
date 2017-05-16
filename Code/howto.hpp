#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class howto : public cScreen{
private:
	bool playing;
public:
	howto(void);
	virtual int Run(sf::RenderWindow &Tela);
};

howto::howto(void){
	playing = false;
}

int howto::Run(sf::RenderWindow &Tela){

	

    // Loop para deixar a janela aberta
    while (Tela.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (Tela.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                Tela.close(); 
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape){
                    return 0;
                }
            }
        }
        Tela.clear(sf::Color::White);
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}