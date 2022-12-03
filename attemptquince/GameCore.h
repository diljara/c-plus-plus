#pragma once
#include <SFML/Graphics.hpp>

class GameCore {

	sf::RenderWindow* window;/*указатель на окно*/
	void update(int elapsed);//elapsed нужен, чтобы движение было плавным, а не рывками. вполне возможно, что не понадобится
	void draw();

public:
	GameCore();
	void start();
	~GameCore();
};

