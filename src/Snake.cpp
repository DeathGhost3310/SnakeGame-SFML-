#include "Snake.h"
#include <random>
#include <SFML/Graphics.hpp>


Snake::Snake(std::shared_ptr<Apple> apple): m_apple(apple) {
	head = Coord{ rand() % (16 + 1), rand() % (16 + 1)};
	m_snake.push_front(head);
}

sf::Color Snake::getColor() {
	return m_color;
}

void Snake::eat_apple(){
	if (m_apple.get()->getCoord().x == head.x && m_apple.get()->getCoord().y == head.y) {
		m_snake.push_back(Coord{ 900, 900 });
		m_apple.get()->randomChangePosition();
	}
}

bool Snake::colided() {
	for (auto it = m_snake.begin();it != m_snake.end();it++) {
		Coord cd = *it;
		if (head.x == cd.x && head.y == cd.y){
			return true;
		}
	}
	return false;
}

void Snake::head_move(Coord cd) {
	head = cd;
}

void Snake::direction_set(direction head_direction) {
	m_head_direction = head_direction;
}

direction Snake::direction_get() {
	return m_head_direction;
}

std::list<Coord> Snake::snake_update(){
	
	if (m_head_direction == direction::UP)
		head.y -= RES_y;
	else if (m_head_direction == direction::DOWN)
		head.y += RES_y;
	else if (m_head_direction == direction::RIGHT)
		head.x += RES_x;
	else if (m_head_direction == direction::LEFT)
		head.x -= RES_x;

	auto it_head = m_snake.begin();
	*it_head = head;
	if (m_snake.size() > 1) {
		auto next_it = m_snake.end();
		next_it--;
		for (auto current_it = m_snake.end(); next_it != m_snake.begin(); current_it--, next_it--) {
			*current_it = *next_it;
		}
	}
	eat_apple();
	if (colided()) {
		m_snake.clear();
		head = Coord{ rand() % (16 + 1), rand() % (16 + 1) };
		m_snake.push_front(head);
		m_head_direction = direction::RIGHT;
	}
	return m_snake;
}