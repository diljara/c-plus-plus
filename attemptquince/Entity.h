#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"

class Entity
{
	sf::Texture tex;	
	Cell* cell;
public:
	Entity(std::string name, Cell* cell);
	void render();
	sf::Sprite sprite;
	unsigned short int power;
};

