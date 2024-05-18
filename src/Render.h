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
	//~Render();
	void update(std::list<Coord> snake); //for the render and update window
	bool isOpen(); // for the check open window
private:

	void snake_render(std::list<Coord> snake); //for the render snake for only class Render 
	void apple_render(); //for the render apple for only class Render
	
	float m_fps;
	std::shared_ptr<Apple> m_apple;
	std::shared_ptr<sf::RenderWindow> m_window; //window
	
	sf::RectangleShape m_rect; //rectangle for the draw in window
};

#endif