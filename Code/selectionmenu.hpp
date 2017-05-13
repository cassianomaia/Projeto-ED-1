#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 5

class selectionmenu{
public:
	selctionmenu(float width, float height);
	~selectionmenu();

	void draw(sf::RenderWindow &Tela);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};


selectionmenu::selectionmenu(float width, float height){
	if (!font.loadFromFile("arial.ttf")){
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Blue);
	menu[0].setString("1");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("2");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("3");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("How to Play");
	menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	menu[4].setFont(font);
	menu[4].setColor(sf::Color::White);
	menu[4].setString("About");
	menu[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

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
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Blue);
	}
}

void selectionmenu::MoveDown(){
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Blue);
	}
}
