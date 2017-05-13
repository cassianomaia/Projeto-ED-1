#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class menu : public cScreen{
private:

public:
	menu(void);
	virtual int Run(sf::RenderWindow &Tela);
};

menu::menu(void){

}

int menu::Run(sf::RenderWindow &Tela){


	sf::RectangleShape title(sf::Vector2f(400, 158));
    sf::Texture textT;
    if (!textT.loadFromFile("../Images/titulo.png")){
        return EXIT_FAILURE;
    }
    title.setTexture(&textT, true);
    title.setPosition(200, 100);

    sf::RectangleShape button(sf::Vector2f(400,60));
    sf::Texture textButton;
    if (!textButton.loadFromFile("../Images/button.png")){
        return EXIT_FAILURE;
    }
    button.setTexture(&textButton, true);
    button.setPosition(200, 358);
    
    sf::RectangleShape howto(sf::Vector2f(400,47));
    sf::Texture textHowt;
    if (!textHowt.loadFromFile("../Images/howto.png")){
        return EXIT_FAILURE;
    }
    howto.setTexture(&textHowt, true);
    howto.setPosition(50, 520);
    
    sf::RectangleShape about(sf::Vector2f(199,47));
    sf::Texture textAbout;
    if (!textAbout.loadFromFile("../Images/about.png")){
        return EXIT_FAILURE;
    }
    about.setTexture(&textAbout, true);
    about.setPosition(550, 520);

     // Loop para deixar a janela aberta

    while (Tela.isOpen()){
         sf::Event event;
         // Checa os eventos em loop
        while (Tela.pollEvent(event)){
             if (event.type == sf::Event::Closed)
                Tela.close(); 
         }
        Tela.clear(sf::Color::White);
        Tela.draw(title);
        Tela.draw(button);
        Tela.draw(howto);
        Tela.draw(about);
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}