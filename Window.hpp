#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    ~Window();

    void Create();
    void Setup();
    void HandleEvents();

    void BeginDraw();
    void EndDraw();

    void SetDone(bool l_done);
    bool IsDone();
    sf::RenderWindow* GetRenderWindow();

private:
    bool m_done;
    sf::RenderWindow m_window;
};

#endif