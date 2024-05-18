#ifndef HEADERS_H
#define HEADERS_H

#pragma once

#include <SFML/Graphics.hpp>
#include <random>

struct Coord
{
	int x;
	int y;
};

const int RES_x = 50;
const int RES_y = 50;
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
	void randomChangePosition() { m_cord.x = rand() % (16 + 1); m_cord.y = rand() % (16 + 1); };
	sf::Color getColor() { return m_color; };
private:
	Coord m_cord;
	sf::Color m_color = sf::Color::Red;
};



#endif
