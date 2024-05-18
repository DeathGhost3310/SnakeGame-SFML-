#include "Render.h"


Render::Render(std::shared_ptr<sf::RenderWindow> window, float fps, std::shared_ptr<Apple> apple)
	:m_window(window), m_fps(fps), m_apple(apple)
{
	m_rect.setSize(rect_size);
}

void Render::snake_render(std::list<Coord> snake) {
	for (auto it = snake.begin();it != snake.end();it++) {
		m_rect.setFillColor(sf::Color::Green);
		Coord cd = *it;
		m_rect.setPosition({ cd.x * 50.f, cd.y * 50.f });
		m_window.get()->draw(m_rect);
	}
}

bool Render::isOpen() {
	if (m_window.get()->isOpen())
		return true;
	else
		return false;
}

void Render::apple_render() {
	m_rect.setPosition( m_apple.get()->getCoord().x, m_apple.get()->getCoord().y);
	m_rect.setFillColor(m_apple.get()->getColor());
	m_window.get()->draw(m_rect);
}

void Render::update(std::list<Coord> snake) {
	m_window.get()->clear(sf::Color::Black);
	
	snake_render(snake);
	apple_render();
	
	m_window.get()->display();
	sf::sleep(sf::milliseconds(1000.f / m_fps));
}