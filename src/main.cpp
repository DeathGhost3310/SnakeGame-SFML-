#include <SFML/Graphics.hpp>
#include <memory>
#include <thread>


#pragma once

#include "Headers.h"
#include "Snake.h"
#include "Render.h"


int main()
{
    std::shared_ptr<sf::RenderWindow> window{ std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 800), "Snake game(SFML)") };
    const float FPS = 10;

    std::shared_ptr<Apple> m_apple{new Apple()};
    std::shared_ptr<Snake> m_snake{new Snake(m_apple) };
    m_apple.get()->randomChangePosition();
    Render m_render(window, FPS, m_apple, m_snake);
    
    
   

    
    while (m_render.isOpen())
    {
        sf::Event event;
        while (window.get()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.get()->close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up && m_snake.get()->direction_get() != direction::DOWN)
                    m_snake.get()->direction_set(direction::UP);
                else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down && m_snake.get()->direction_get() != direction::UP)
                    m_snake.get()->direction_set(direction::DOWN);
                else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right && m_snake.get()->direction_get() != direction::LEFT)
                    m_snake.get()->direction_set(direction::RIGHT);
                else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left && m_snake.get()->direction_get() != direction::RIGHT)
                    m_snake.get()->direction_set(direction::LEFT);
                else if (event.key.code == sf::Keyboard::R)
                    m_snake.get()->snakeRestart();
            }
            
        }
        m_snake.get()->snake_update();
        m_render.update();
    }
    
    return 0;
}


