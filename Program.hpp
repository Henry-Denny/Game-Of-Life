#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <cstring>

#include <SFML/System.hpp>

#include "Window.hpp"

class Program
{
public:
    Program();
    ~Program();

    bool LoadCellsFromImage(std::string l_pathName);
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

    bool m_cells[100][100];
};

#endif