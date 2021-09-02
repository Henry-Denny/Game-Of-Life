#include "Constants.hpp"
#include "Program.hpp"

Program::Program() : m_cells(constants::gridSize.x, std::vector<bool>(constants::gridSize.x, false))
{
    Setup();
}

Program::~Program() {}

bool Program::LoadCellsFromImage(std::string l_pathName)
{
    sf::Image cellData;
    if (!cellData.loadFromFile(l_pathName)) { return false; }
    if (cellData.getSize().x > constants::gridSize.x || cellData.getSize().y > constants::gridSize.y) { return false; }
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
    m_cellRect.setSize(sf::Vector2f(constants::cellSize, constants::cellSize));
    m_cellRect.setFillColor(sf::Color::White);
    RestartClock();
}

void Program::HandleInput()
{
    m_window.HandleEvents();
}

void Program::Update()
{
    if (m_elapsed >= constants::defaultTickTime)
    {
        Tick();
        m_elapsed -= constants::defaultTickTime;
    }
}

void Program::Tick()
{
    // Update cell states
    for (unsigned int x = 0; x < constants::gridSize.x; ++x)
    {
        for (unsigned int y = 0; y < constants::gridSize.y; ++y)
        {
            int numNeighbours = GetNumAliveNeighbours({x, y});

            if (m_cells[x][y])
            {
                m_cells[x][y] = (numNeighbours >= 2 && numNeighbours <= 3);
            }
            else
            {
                m_cells[x][y] = (numNeighbours == 3);
            }
            
        }
    }
}

int Program::GetNumAliveNeighbours(sf::Vector2u activeCellPos)
{
    int numNeighbours = 0;
    for (int relX = -1; relX <= 1; ++relX)
    {
        for (int relY = -1; relY <= 1; ++relY)
        {
            // Don't count the active cell
            if (relX == 0 && relY == 0) { continue; }
            if (activeCellPos.x == 0 || activeCellPos.x >= (constants::gridSize.x - 1) || activeCellPos.y == 0 || activeCellPos.y >= (constants::gridSize.y - 1))
            {
                continue;
            }
            if (m_cells[activeCellPos.x + relX][activeCellPos.y + relY]) { ++numNeighbours; }
        }
    }
    return numNeighbours;
}

void Program::Draw()
{
    m_window.BeginDraw();
    sf::RenderWindow *l_wind = m_window.GetRenderWindow();
    for (int x = 0; x < constants::gridSize.x; ++x)
    {
        for (int y = 0; y < constants::gridSize.y; ++y)
        {
            if (m_cells[x][y])
            {
                m_cellRect.setPosition(x * constants::cellSize, y * constants::cellSize);
                l_wind->draw(m_cellRect);
            }
        }
    }
    m_window.EndDraw();
}

void Program::RestartClock()
{
    m_elapsed += m_clock.restart().asSeconds();
}

Window* Program::GetWindow() { return &m_window; }