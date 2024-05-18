#include <SFML/Graphics.hpp>
#include <memory>

#pragma once

#include "Headers.h"
#include "Snake.h"
#include "Render.h"


int main()
{
    std::shared_ptr<sf::RenderWindow> window{ std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 800), "Snake game(SFML)") };
    const float FPS = 5;
    
    std::shared_ptr<Apple> m_apple{new Apple()};
    m_apple.get()->randomChangePosition();
    Render m_render(window, FPS, m_apple);
    Snake m_snake(m_apple);
    


    while (m_render.isOpen())
    {
        sf::Event event;
        while (window.get()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.get()->close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W && m_snake.direction_get() != direction::DOWN)
                    m_snake.direction_set(direction::UP);
                else if (event.key.code == sf::Keyboard::S && m_snake.direction_get() != direction::UP)
                    m_snake.direction_set(direction::DOWN);
                else if (event.key.code == sf::Keyboard::D && m_snake.direction_get() != direction::LEFT)
                    m_snake.direction_set(direction::RIGHT);
                else if (event.key.code == sf::Keyboard::A && m_snake.direction_get() != direction::RIGHT)
                    m_snake.direction_set(direction::LEFT);
                else if (event.key.code == sf::Keyboard::R)
                    m_snake.snakeRestart();
            }
            
        }
        m_render.update(m_snake.snake_update());
    }

    return 0;
}


