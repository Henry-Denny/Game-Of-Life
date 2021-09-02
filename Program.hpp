#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <SFML/System.hpp>

#include "Window.hpp"

class Program
{
public:
    Program();
    ~Program();

    void Setup();
    void HandleInput();
    void Update();
    void Draw();
    void RestartClock();

    Window* GetWindow();

private:
    void Tick();

    Window m_window;
    sf::Clock m_clock;
    float m_elapsed;
};

#endif