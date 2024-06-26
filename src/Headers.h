#ifndef HEADERS_H
#define HEADERS_H

#pragma once

#include <SFML/Graphics.hpp>
#include <random>

struct Coord
{
	int x = 0;
	int y = 0;
};


const int RES_x = 25;
const int RES_y = 25;
const sf::Vector2f rect_size = { RES_x, RES_y};


enum direction {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

class Apple
{
public:
	Apple() { randomChangePosition(); };
	//~Apple();
	Coord getCoord() { return m_cord; };
	void randomChangePosition() { m_cord = Coord{ rand() % (14 + 1), rand() % (14 + 1) }; };
	sf::Color getColor() { return m_color; };
private:
	Coord m_cord;
	sf::Color m_color = sf::Color::Red;
};



#endif
