#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "Constants.hpp"

class Window
{
public:
    Window();
    ~Window();

    void Create();
    void Setup();
    void HandleEvents(std::vector<std::vector<bool>> &l_cells, bool &l_paused);

    void BeginDraw();
    void EndDraw();

    void SetDone(bool l_done);
    bool IsDone();
    sf::RenderWindow* GetRenderWindow();
    sf::Vector2u GetSize();

private:
    bool m_done;
    sf::RenderWindow m_window;
    std::vector<sf::Vector2u> m_selectedCells;
};

#endif