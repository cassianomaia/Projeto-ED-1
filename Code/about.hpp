#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class about : public cScreen{
private:
    sf::Font font;
    sf::Text esc;
public:
	about(void);
	virtual int Run(sf::RenderWindow &Tela);
};

about::about(void){
}

int about::Run(sf::RenderWindow &Tela){

    if (!font.loadFromFile("../Fonts/Roboto-Regular.ttf")){
        return (-1);
    }
    esc.setFont(font);
    esc.setFillColor(sf::Color::Black);
    esc.setString("Pressione ESC para sair.");
    esc.setPosition(sf::Vector2f(25, 550));
    esc.setCharacterSize(20);

    sf::RectangleShape about(sf::Vector2f(199,47));
    sf::Texture textAbout;
    if (!textAbout.loadFromFile("../Images/about.png")){
        return (-1);
    }
    about.setTexture(&textAbout, true);
    about.setPosition(300, 100);

    sf::RectangleShape abouttext(sf::Vector2f(621,255));
    sf::Texture aboutimg;
    if (!aboutimg.loadFromFile("../Images/abouttext.png")){
        return (-1);
    }
    abouttext.setTexture(&aboutimg, true);
    abouttext.setPosition(90, 200);
    
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
        Tela.draw(about);
        Tela.draw(abouttext);
        Tela.draw(esc);
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}