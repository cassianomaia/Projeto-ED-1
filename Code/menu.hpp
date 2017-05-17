#include "cScreen.hpp"
#include "selectionmenu.hpp"
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

	selectionmenu menu1(400, 600);
	
	sf::RectangleShape title(sf::Vector2f(400, 158));
    sf::Texture textT;
    if (!textT.loadFromFile("../Images/titulo.png")){
        return (-1);
    }
    title.setTexture(&textT, true);
    title.setPosition(200, 50);

     // Loop para deixar a janela aberta

    while (Tela.isOpen()){
         sf::Event event;
         // Checa os eventos em loop
        while (Tela.pollEvent(event)){
            switch (event.type){
            	case sf::Event::Closed:
            		Tela.close();
            	break;

            	case sf::Event::KeyReleased:
            		switch (event.key.code){
            			case sf::Keyboard::Up:
            				menu1.MoveUp();
            			break;
            			case sf::Keyboard::Down:
            				menu1.MoveDown();
            			break;
            			case sf::Keyboard::Return:
            				return (menu1.GetPressedItem());
            			break;
            		}
            	break;
            }

         }

        Tela.clear(sf::Color::White);
        Tela.draw(title);
        menu1.draw(Tela);
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}