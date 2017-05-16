#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class about : public cScreen{
private:
public:
	about(void);
	virtual int Run(sf::RenderWindow &Tela);
};

about::about(void){
}

int about::Run(sf::RenderWindow &Tela){
    sf::RectangleShape about(sf::Vector2f(199,47));
    sf::Texture textAbout;
    if (!textAbout.loadFromFile("../Images/about.png")){
        return EXIT_FAILURE;
    }
    about.setTexture(&textAbout, true);
    about.setPosition(300, 100);

    sf::RectangleShape abouttext(sf::Vector2f(621,255));
    sf::Texture aboutimg;
    if (!aboutimg.loadFromFile("../Images/abouttext.png")){
        return EXIT_FAILURE;
    }
    abouttext.setTexture(&aboutimg, true);
    abouttext.setPosition(90, 150);
    
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
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}