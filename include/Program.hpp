#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <cstring>
#include <vector>

#include <SFML/Graphics.hpp>
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
    int GetNumAliveNeighbours(sf::Vector2u activeCellPos);

    Window m_window;
    sf::Clock m_clock;
    float m_elapsed;
    bool m_paused;

    std::vector<std::vector<bool>> m_cells;
    sf::RectangleShape m_cellRect;
};

#endif