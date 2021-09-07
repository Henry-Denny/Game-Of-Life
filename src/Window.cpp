#include "Window.hpp"

Window::Window()
{
    Create();
    Setup(); 
}

Window::~Window() {}

void Window::Create()
{
    m_window.create({constants::gridSize.x * constants::cellSize, constants::gridSize.y * constants::cellSize}, "Game Of Life");
}

void Window::Setup()
{
    m_done = false;
}

void Window::HandleEvents(std::vector<std::vector<bool>> &l_cells, bool &l_paused)
{
    sf::Event ev;
    while (m_window.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
        {
            m_done = true;
        }
        else if (ev.type == sf::Event::KeyPressed)
        {
            switch (ev.key.code)
            {
            case (sf::Keyboard::Space):
                l_paused = !l_paused;
                break;
            
            default:
                break;
            }
        }
        else if (ev.type == sf::Event::MouseButtonReleased)
        {
            if (ev.mouseButton.button == sf::Mouse::Left)
            {
                // Reset selected cells
                while (m_selectedCells.begin() != m_selectedCells.end())
                {
                    m_selectedCells.erase(m_selectedCells.begin());
                }
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
            if (mousePos.x < 0 || mousePos.x >= m_window.getSize().x || mousePos.y < 0 || mousePos.y >= m_window.getSize().y)
            {
                continue;
            }
            sf::Vector2u cellPos((mousePos.x) / constants::cellSize, mousePos.y / constants::cellSize);
            for (auto itr = m_selectedCells.begin(); itr != m_selectedCells.end(); ++itr)
            {
                if (*itr == cellPos) { return; }
            }
            l_cells[cellPos.x][cellPos.y] = !l_cells[cellPos.x][cellPos.y];
            m_selectedCells.push_back(cellPos);
        }
    }
}

void Window::BeginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::EndDraw()
{
    m_window.display();
}

bool Window::IsDone() { return m_done; }
sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }