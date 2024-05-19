#include "Snake.h"
#include <random>
#include <SFML/Graphics.hpp>


Snake::Snake(std::shared_ptr<Apple> apple): m_apple(apple) {
	head = Coord{5,5 /*rand() % (16 + 1), rand() % (16 + 1)*/}; //set start pos head
	m_snake.push_front(head); //push head in snake 
}

Snake::Snake() {
	head = Coord{ 5,5 /*rand() % (16 + 1), rand() % (16 + 1)*/ }; //set start pos head
	m_snake.push_front(head); //push head in snake 
}

int Snake::snake_size() {
	return m_snake.size();
}

std::list<Coord>& Snake::get_snake() {
	return m_snake;
}

sf::Color Snake::getColor() { //return snake collor
	return m_color;
}

void Snake::eat_apple(){ //for the check colided snake and apple
	if (m_apple.get()->getCoord().x == head.x && m_apple.get()->getCoord().y == head.y) {
		m_snake.push_back(Coord{ 900, 900});
		m_apple.get()->randomChangePosition();
	}
}

bool Snake::colided() { //for the check collision 
	for (auto it = m_snake.begin()++;it != m_snake.end();it++) {
		Coord cd = *it;
		if (head.x == cd.x && head.y == cd.y){
			return true;
		}
	}
	return false;
}

void Snake::head_move(Coord cd) { //change head cord
	head = cd;
}

void Snake::direction_set(direction head_direction) { //set snake direction
	m_head_direction = head_direction;
}

direction Snake::direction_get() { //get snake direction
	return m_head_direction;
}

void Snake::snakeRestart() {
	m_snake.front().x = 9999; //Restart code
}

std::list<Coord> Snake::snake_update(){
	
	if (m_head_direction == direction::UP) // head move
		head.y -= 1;
	else if (m_head_direction == direction::DOWN)
		head.y += 1;
	else if (m_head_direction == direction::RIGHT)
		head.x += 1;
	else if (m_head_direction == direction::LEFT)
		head.x -= 1;
	
	if (head.x > 15) //if head move in borders
		head.x = 0;
	if (head.x < 0)
		head.x = 15;
		if (head.y > 15)
			head.y = 0;
		if (head.y < 0)
			head.y = 15;

	if (colided() && m_snake.size() > 2 || m_snake.front().x == 9999) { //check the snake for collision and check used restart
			m_snake.clear(); // reset snake to start if snake colided
			head = Coord{ rand() % (14 + 1), rand() % (14 + 1) };
			m_snake.push_front(head);
			m_head_direction = direction::RIGHT;
			m_apple.get()->randomChangePosition();
	}
	
	auto it_head = m_snake.begin();
	if (m_snake.size() > 1) { // starting point of the body
		auto it_start_point_body = m_snake.begin();
		it_head++;
		*it_head = *it_start_point_body;
		it_head--;
	}
	*it_head = head; // fixate head move
	
	
	if (m_snake.size() > 2) { //body move
		auto next_it = m_snake.end();
		next_it--;
		next_it--;
		for (auto current_it = m_snake.end()--; next_it != m_snake.begin(); next_it--) {
			current_it--;
			*current_it = *next_it;
		}
	}
	eat_apple();
	
	return m_snake; // return snake for the render
}