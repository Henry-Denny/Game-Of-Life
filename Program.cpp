#include "Program.hpp"

Program::Program()
{
    Setup();
}

Program::~Program() {}

bool Program::LoadCellsFromImage(std::string l_pathName)
{
    sf::Image cellData;
    if (!cellData.loadFromFile(l_pathName)) { return false; }
    if (cellData.getSize().x != 100 || cellData.getSize().y != 100) { return false; }
    for (int x = 0; x < cellData.getSize().x; ++x)
    {
        for (int y = 0; y < cellData.getSize().y; ++y)
        {
            m_cells[x][y] = !(cellData.getPixel(x, y) == sf::Color::Black);
        }
    }
}

void Program::Setup()
{
    // Load image into memory
    RestartClock();
}

void Program::HandleInput()
{
    m_window.HandleEvents();
}

void Program::Update()
{
    if (m_elapsed >= 0.5f)
    {
        Tick();
        m_elapsed -= 0.5f;
    }
}

void Program::Tick()
{
    // Update state
}

void Program::Draw()
{
    // Draw cells on screen
}

void Program::RestartClock()
{
    m_elapsed += m_clock.restart().asSeconds();
}

Window* Program::GetWindow() { return &m_window; }