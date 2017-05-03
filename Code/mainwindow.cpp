#include <SFML/Graphics.hpp>
/*)
void mainwindow (){
    window.clear(sf::Color::Blue);
    sf::RectangleShape title(200,200);
    title.color(sf::Color::Green);
    title.setposition(600, 300);
}

/*
void levelselect(){
    window.clear(sf::Color::Blue);

}

void startlevel(){
    window.clear(sf::Color::Blue);

}
*/

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pianus");
    window.clear(sf::Color::White);
   
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
    button.setPosition(247, 303);
    
    sf::RectangleShape howto(sf::Vector2f(128,30));
    sf::Texture textHowt;
    if (!textHowt.loadFromFile("../Images/howto.png"))
    {
        return EXIT_FAILURE;
    }
    howto.setTexture(&textHowt, true);
    howto.setPosition(136, 520);
    
    sf::RectangleShape about(sf::Vector2f(257,30));
    sf::Texture textAbout;
    if (!textAbout.loadFromFile("../Images/about.png"))
    {
        return EXIT_FAILURE;
    }
    about.setTexture(&textAbout, true);
    about.setPosition(472, 520);

    // Loop para deixar a janela aberta
    while (window.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close(); 
        }
        window.clear(sf::Color::White);
        window.draw(title);
        window.draw(button);
        window.draw(howto);
        window.draw(about);
        window.display();
    }
    return 0;
}