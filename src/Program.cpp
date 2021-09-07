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
    m_paused = true;
    m_cellRect.setSize(sf::Vector2f(constants::cellSize, constants::cellSize));
    m_cellRect.setFillColor(sf::Color::White);

    m_font.loadFromFile("./res/otomanopee.ttf");
    m_pausedTBox.setString("Paused...");
    m_pausedTBox.setFillColor(sf::Color(150, 150, 255));
    m_pausedTBox.setFont(m_font);
    m_pausedTBox.setCharacterSize(50);
    
    sf::FloatRect pauseTBoxRect = m_pausedTBox.getLocalBounds();
    m_pausedTBox.setOrigin(pauseTBoxRect.left + (pauseTBoxRect.width / 2.0f), 0);
    m_pausedTBox.setPosition(m_window.GetSize().x / 2.0f, 25);
    RestartClock();
}

void Program::HandleInput()
{
    m_window.HandleEvents(m_cells, m_paused);
}

void Program::Update()
{
    if (m_elapsed >= constants::defaultTickTime)
    {
        if (!m_paused) { Tick(); }
        
        m_elapsed -= constants::defaultTickTime;
    }
}

void Program::Tick()
{
    auto l_newGen = m_cells;
    // Update cell states
    for (unsigned int x = 0; x < constants::gridSize.x; ++x)
    {
        for (unsigned int y = 0; y < constants::gridSize.y; ++y)
        {
            int numNeighbours = GetNumAliveNeighbours({x, y});

            if (m_cells[x][y])
            {
                l_newGen[x][y] = (numNeighbours >= 2 && numNeighbours <= 3);
            }
            else
            {
                l_newGen[x][y] = (numNeighbours == 3);
            }
            
        }
    }
    m_cells = l_newGen;
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
    if (m_paused) { l_wind->draw(m_pausedTBox); }
    m_window.EndDraw();
}

void Program::RestartClock()
{
    m_elapsed += m_clock.restart().asSeconds();
}

Window* Program::GetWindow() { return &m_window; }