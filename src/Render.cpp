#include "Render.h"
#include <string>

Render::Render(std::shared_ptr<sf::RenderWindow> window, float fps, std::shared_ptr<Apple> apple)
	:m_window(window), m_fps(fps), m_apple(apple)
{
	m_rect.setSize(rect_size);
}

void Render::snake_render(std::list<Coord> snake) {
	for (auto it = snake.begin();it != snake.end() && snake.size() > 1;it++) {
		m_rect.setFillColor(sf::Color::Green);
		Coord cd = *it;
		m_rect.setPosition({ cd.x * 25.f + indent_x, cd.y * 25.f + indent_y });
		m_window.get()->draw(m_rect);
	}
	if (snake.size() == 1) {
		m_rect.setFillColor(sf::Color::Green);
		m_rect.setPosition({ snake.front().x * 25.f + indent_x, snake.front().y * 25.f + indent_y });
		m_window.get()->draw(m_rect);

	}
}
bool Render::isOpen() {
	if (m_window.get()->isOpen())
		return true;
	else
		return false;
}

void Render::borders_render() {
	m_rect.setFillColor(sf::Color::White);
	for (int i = 0;i < 18;i++) {
		m_rect.setPosition(i * RES_x, 0 * RES_y);
		m_window.get()->draw(m_rect);

		m_rect.setPosition(i * RES_x, 17 * RES_y);
		m_window.get()->draw(m_rect);
	}
	for (int i = 0;i < 17;i++) {
		m_rect.setPosition(0 * RES_x, i * RES_y);
		m_window.get()->draw(m_rect);

		m_rect.setPosition(17 * RES_x, i * RES_y);
		m_window.get()->draw(m_rect);
	}
}

void Render::apple_render() {
	m_rect.setPosition( m_apple.get()->getCoord().x * 25.f + indent_x, m_apple.get()->getCoord().y * 25.f + indent_y);
	m_rect.setFillColor(m_apple.get()->getColor());
	m_window.get()->draw(m_rect);
}

void Render::score_render(const std::list<Coord> snake) {
	if (!font.loadFromFile("../assets/fonts/appetite-italic.ttf"))
		return;
	int score = snake.size();
	txt.setFont(font);
	txt.setFillColor(sf::Color::Cyan);
	txt.setCharacterSize(48);
	txt.setPosition(490, 10);
	txt.setString("SCORE:");
	m_window.get()->draw(txt);
	txt.setPosition(500, 50);
	txt.setString(std::to_string(score));
	m_window.get()->draw(txt);
}

void Render::update(std::list<Coord> snake) {
	m_window.get()->clear(sf::Color::Black);
	
	borders_render();
	snake_render(snake);
	apple_render();
	score_render(snake);


	m_window.get()->display();
	sf::sleep(sf::milliseconds(1000.f / m_fps));
}