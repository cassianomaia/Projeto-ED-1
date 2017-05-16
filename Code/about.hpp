#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class about : public cScreen{
private:
	bool playing;
    sf::Text abouttext;
    sf::Font aboutfont;
public:
	about(void);
	virtual int Run(sf::RenderWindow &Tela);
};

about::about(void){
	playing = false;
}

int about::Run(sf::RenderWindow &Tela){
    if (!aboutfont.loadFromFile("piano2.ttf")){
        //error
    }
	abouttext.setFont(aboutfont);
    abouttext.setFillColor(sf::Color::Black);
    abouttext.setString("Pianus é inspirado no Genius, primeiro jogo eletrônico vendido no país e um dos maiores sucessos da década de 80.     O jogo estimula a memorização de sequências e sons e a capacidade de percepção em um formato similar a um teclado real. São 13 teclas a serem tocadas em uma determinada ordem e, se o usuário tiver sucesso, a série se torna progressivamente mais longa e mais complexa conforme a música. Uma vez que o usuário falhar, o jogo acaba. 
Além disso, é composto por 3 níveis com diferentes dificuldades musicais dependendo da escolha do jogador. O nível um corresponde à música “Brilha Brilha Estrelinha”; a segunda música é “9ª Sinfonia - Beethoven” e o terceiro nível é composto pela música “Concerning Hobbits”.");
    abouttext.setPosition(sf::Vector2f(300,300));
    abouttext.setCharacterSize(30);

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
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}