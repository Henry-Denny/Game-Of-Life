#include "Window.hpp"

Window::Window()
{
    Create();
    Setup(); 
}

Window::~Window() {}

void Window::Create()
{
    m_window.create({1200, 1000}, "Game Of Life");
}

void Window::Setup()
{
    m_done = false;
}

void Window::HandleEvents()
{
    sf::Event ev;
    while (m_window.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
        {
            m_done = true;
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

void Window::SetDone(bool l_done) { m_done = l_done; }
bool Window::IsDone() { return m_done; }
sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }