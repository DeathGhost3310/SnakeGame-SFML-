#ifndef RENDER_H
#define RENDER_H

#pragma once

#include "Headers.h"

#include <memory>
#include <list>
#include <SFML/Graphics.hpp>

class Render
{
public:
	
	Render(std::shared_ptr<sf::RenderWindow> window,float fps, std::shared_ptr<Apple> apple);
	~Render();
	void update(std::list<Coord> snake);
	bool isOpen();
private:

	void snake_render(std::list<Coord> snake);
	void apple_render();
	
	float m_fps;
	std::shared_ptr<Apple> m_apple;
	std::shared_ptr<sf::RenderWindow> m_window;
	
	sf::RectangleShape m_rect;
};

#endif