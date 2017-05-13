#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class jogo : public cScreen{
private:
public:
	jogo(void);
	virtual int Run(sf::RenderWindow &Tela);
};

jogo::jogo(void){

}

int jogo::Run(sf::RenderWindow &Tela){

	sf::RectangleShape piano(sf::Vector2f(400, 400));
    piano.setPosition(200, 100);
    piano.setFillColor(sf::Color::Black);

    // Loop para deixar a janela aberta
    while (Tela.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (Tela.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                Tela.close(); 
            }
        }
        Tela.clear(sf::Color::White);
        Tela.draw(piano);
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}