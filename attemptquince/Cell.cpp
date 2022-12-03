#include "Cell.h"


Cell::Cell(float x, float y, sf::RenderWindow* window, int radius)
{
    sf::CircleShape hexagon(radius, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(radius, radius);
    this->coord.x = x;
    this->coord.y = y;
    hexagon.setPosition(x, y);
    this->window = window;
    this->Player_status = 0;
    this->radius = radius;
}

sf::RenderWindow* Cell::get_window()
{
    return this->window;
}

void Cell::render()
/*рисует шестиугольник aka клетку*/
{
    sf::CircleShape hexagon(radius, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::Green);
    hexagon.setOrigin(radius, radius);
    hexagon.setPosition(coord.x, coord.y);
    sf::RenderWindow* win = this->get_window();
    win->draw(hexagon);

}

sf::Vector2f Cell::get_coord()
{
    return coord;
}

bool Cell::IsinCell(sf::Vector2i point)
{
    int distsq = point.x * point.x + point.y * point.y;
    if (distsq > radius * radius) return false;
    if (4*distsq <= 3 * radius * radius) return true;
    return false;

}
