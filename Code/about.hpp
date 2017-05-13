#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class about : public cScreen{
private:
	bool playing;
public:
	about(void);
	virtual int Run(sf::RenderWindow &Tela);
};

about::about(void){
	playing = false;
}

int about::Run(sf::RenderWindow &Tela){

	

    // Loop para deixar a janela aberta
    while (Tela.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (Tela.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                Tela.close(); 
            }
        }
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}