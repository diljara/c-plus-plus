#pragma once
#include <SFML/Graphics.hpp>

class Cell
{
public:
	Cell(float x, float y, sf::RenderWindow* window, int radius = 25);
	sf::RenderWindow* get_window();
	void render();
	sf::Vector2i get_coord();
	bool IsinCell(sf::Vector2i mouse_pos);
	
private:
	sf::Vector2i coord;/*координаты*/
	sf::RenderWindow* window;
	unsigned short int Player_status;
	int radius;
};

