#include "GameCore.h"
#include <iostream>
#include "Cell.h"
#include "Entity.h"


void GameCore::update(int elapsed)
/*обновляет экран, в случае нажатия кнопки escape или закрытия окна, закрывает окно*/
{
    sf::Event event;
    bool drag = false;
    window->setFramerateLimit(60);
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) 
                window->close();
        }
            
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window->getPosition();
                std::cout << '1';


                

            }
        }
        
    }
}

void GameCore::draw()
/*отрисовывает карту, ну или должна в теории*/
{
    window->clear(sf::Color::Yellow);
    

    float a = 500;
    float b = 500;
    Cell cell = Cell(a, b, window);
    cell.render();
    /*for (auto cell : map)
        cell->render();*/
    const int x = 20;
    const int y = 20;
    Cell* map[x][y];
    //это не очень высчитывать массив каждый раз, но я это пока оставлю так
    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 20; ++x) {
            Cell cell = Cell((y % 2 ? 75 : 50) + x * 50.f, 50 + y * 40.f, window);
            map[x][y] = &cell;
            map[x][y]->render();
            Entity entity = Entity("wild.png", &cell);
            window->draw(entity.sprite);
        }
    }
    std::cout<<map[0][0]->IsinCell(sf::Mouse::getPosition());
        
    //Entity entity = Entity("wild.png", &cell);
    
    //window->draw(entity.sprite);


    window->display();
}

void GameCore::start() 
/*запускает цикл из функций update, draw*/
{
	sf::Clock clc;
	while (window->isOpen()) {
		int elapsed = clc.restart().asMilliseconds();
		update(elapsed);
		draw();
	}
	
}

GameCore::GameCore()
/*конструктор создает окно*/
{
    window = new sf::RenderWindow({ 1100, 900 }, "Antiyoy", sf::Style::None);
}

GameCore::~GameCore()
/*деструктор удаляет окно*/
{
    delete window;
}
