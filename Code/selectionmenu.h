#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 5

class selectionmenu{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
public:
	selectionmenu(float width, float height);
	~selectionmenu();

	void draw(sf::RenderWindow &Tela);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
};


selectionmenu::selectionmenu(float width, float height){

	
	if (!font.loadFromFile("piano2.ttf")){
		//error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("1");
	menu[0].setPosition(sf::Vector2f(width / 2, 300));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("2");
	menu[1].setPosition(sf::Vector2f(width / 2, 350));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("3");
	menu[2].setPosition(sf::Vector2f(width / 2, 400));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("How to Play");
	menu[3].setPosition(sf::Vector2f(width / 2, 450));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::Black);
	menu[4].setString("About");
	menu[4].setPosition(sf::Vector2f(width / 2, 500));

	selectedItemIndex = 0;
}


selectionmenu::~selectionmenu(){
}

void selectionmenu::draw(sf::RenderWindow &Tela){
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		Tela.draw(menu[i]);
	}
}

void selectionmenu::MoveUp(){
	if (selectedItemIndex - 1 >= 0){
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void selectionmenu::MoveDown(){
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}
