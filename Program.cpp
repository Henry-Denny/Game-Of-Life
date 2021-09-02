#include "Program.hpp"

Program::Program()
{
    Setup();
}

Program::~Program() {}

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