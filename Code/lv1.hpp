#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "fila.h"
#include <SFML/Audio.hpp>

class lv1 : public cScreen{
private:
public:
	lv1(void);
	virtual int Run(sf::RenderWindow &Tela);
};

lv1::lv1(void){

}

int lv1::Run(sf::RenderWindow &Tela){
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../Sounds/68437__pinkyfinger__piano-a.wav"))
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    

	sf::RectangleShape piano(sf::Vector2f(400, 400));
    piano.setPosition(200, 100);
    piano.setFillColor(sf::Color::Black);

    // Loop para deixar a janela aberta
    while (Tela.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (Tela.pollEvent(event)){
            switch (event.type){ 
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                        case sf::Keyboard::Return:
                            sound.play();
                        break;
                    }
                break;
                case sf::Event::Closed:
                    Tela.close();
                break; 
            }
        }
        Tela.clear(sf::Color::White);
        Tela.draw(piano);
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}