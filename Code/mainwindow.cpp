#include <SFML/Graphics.hpp>
#include <fila.h>
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
    sf::RectangleShape title(sf::Vector2f(600, 100));
    title.setFillColor(sf::Color::Green);
    title.setPosition(100, 100);

    sf::RectangleShape button1(sf::Vector2f(100,50));
    button1.setFillColor(sf::Color::Green);
    button1.setPosition(350, 250);
    sf::RectangleShape button2(sf::Vector2f(100,50));
    button2.setFillColor(sf::Color::Green);
    button2.setPosition(350, 325);
    sf::RectangleShape button3(sf::Vector2f(100,50));
    button3.setFillColor(sf::Color::Green);
    button3.setPosition(350, 400);
    sf::RectangleShape button4(sf::Vector2f(50,30));
    button4.setFillColor(sf::Color::Green);
    button4.setPosition(730, 550);

    // Loop para deixar a janela aberta
    while (window.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close(); 
        }
        window.clear(sf::Color::Blue);
        window.draw(title);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
        window.display();
    }
    return 0;
}