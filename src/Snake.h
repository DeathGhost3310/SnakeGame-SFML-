#ifndef SNAKE_H
#define SNAKE_H

#pragma once

#include <memory>
#include <list>
#include "Headers.h"
#include <SFML/Graphics.hpp>

class Snake
{
public:
	Snake(std::shared_ptr<Apple> apple);
	~Snake();
	void eat_apple();
	std::list<Coord> snake_update();
	void head_move(Coord cd);
	void direction_set(direction head_direction);
	direction direction_get();
	bool colided();
	sf::Color getColor();
private:
	direction m_head_direction = direction::RIGHT;
	std::shared_ptr<Apple> m_apple;
	Coord head;
	std::list<Coord> m_snake;
	sf::Color m_color = sf::Color::Green;
};

#endif