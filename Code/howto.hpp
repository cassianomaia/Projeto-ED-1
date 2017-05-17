#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class howto : public cScreen{
private:
    sf::Font font;
    sf::Text esc;
public:
	howto(void);
	virtual int Run(sf::RenderWindow &Tela);
};

howto::howto(void){
}

int howto::Run(sf::RenderWindow &Tela){
    if (!font.loadFromFile("../Fonts/Roboto-Regular.ttf")){
        return (-1);
    }
    esc.setFont(font);
    esc.setFillColor(sf::Color::Black);
    esc.setString("Pressione ESC para sair.");
    esc.setPosition(sf::Vector2f(50, 570));
    esc.setCharacterSize(20);

    sf::RectangleShape howto(sf::Vector2f(400,47));
    sf::Texture texthowto;
    if (!texthowto.loadFromFile("../Images/howto.png")){
        rereturn (-1);
    }
    howto.setTexture(&texthowto, true);
    howto.setPosition(200, 30);

    sf::RectangleShape howtotext(sf::Vector2f(518,480));
    sf::Texture howtoimg;
    if (!howtoimg.loadFromFile("../Images/howtotext.png")){
        rereturn (-1);
    }
    howtotext.setTexture(&howtoimg, true);
    howtotext.setPosition(141, 90);

	

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
        Tela.draw(howto);
        Tela.draw(howtotext);
        Tela.draw(esc);
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}