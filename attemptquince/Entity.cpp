#include "Entity.h"
#include "Cell.h"

Entity::Entity(std::string name, Cell* cell) {
	tex.loadFromFile(name);
	tex.setSmooth(true);
	tex.setRepeated(true);
	sprite.setTexture(tex);
	sprite.setScale(0.3, 0.3);
	sf::Vector2i delta;
	delta.x = -25;
	delta.y = -33;
	sprite.setPosition(sf::Vector2f(cell->get_coord() + delta));
	this->cell = cell;
	this->power = 0;

}

void Entity::render()
{
	Cell* cell = this->cell;
	sf::RenderWindow* win = cell->get_window();
	win->draw(sprite);
}
