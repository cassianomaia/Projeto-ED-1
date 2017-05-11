#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class menu : public cScreen
{
private:
	bool playing;
public:
	menu(void);
	virtual int Run(sf::RenderWindow &App);
};

menu::menu(void)
{
	playing = false;
}

int menu::Run(sf::RenderWindow &App)
{
	App.clear(sf::Color::White);
	sf::RectangleShape title(sf::Vector2f(300, 118));
    sf::Texture textT;
    if (!textT.loadFromFile("../Images/titulo.png"))
    {
        return EXIT_FAILURE;
    }
    title.setTexture(&textT, true);
    title.setPosition(250, 100);

    sf::RectangleShape button(sf::Vector2f(305,35));
    sf::Texture textButton;
    if (!textButton.loadFromFile("../Images/button.png"))
    {
        return EXIT_FAILURE;
    }
    button.setTexture(&textButton, true);
    button.setPosition(247, 343);
    
    sf::RectangleShape howto(sf::Vector2f(128,20));
    sf::Texture textHowt;
    if (!textHowt.loadFromFile("../Images/howto.png"))
    {
        return EXIT_FAILURE;
    }
    howto.setTexture(&textHowt, true);
    howto.setPosition(136, 520);
    
    sf::RectangleShape about(sf::Vector2f(200,20));
    sf::Texture textAbout;
    if (!textAbout.loadFromFile("../Images/about.png"))
    {
        return EXIT_FAILURE;
    }
    about.setTexture(&textAbout, true);
    about.setPosition(472, 520);

    // Loop para deixar a janela aberta
    while (App.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (App.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                App.close(); 
        }
        App.clear(sf::Color::White);
        App.draw(title);
        App.draw(button);
        App.draw(howto);
        App.draw(about);
        App.display();
    }

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}