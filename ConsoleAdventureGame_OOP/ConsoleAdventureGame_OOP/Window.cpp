#include "Window.h"

#include <iostream>

#include "Player.h"
#include "Spell.h"

Window* Window::getInstance()
{
    static Window instance;
    return &instance;
}

void Window::InitializeWindow(Map& currentMap)
{
    size_t mapWidth = currentMap.getWidth();
    size_t mapHeight = currentMap.getHeight();

    size_t windowSize = mapWidth * mapHeight + mapHeight;

    if (m_window)
        delete m_window;

    m_window = new char[windowSize];

    // Initialize just to be safe
    for (int i = 0; i < windowSize; ++i)
        m_window[i] = 'o';

    // End of lines
    {
        int i = 0;
        while (i < windowSize)
        {
            m_window[i + mapWidth] = '\n';
            i += (int)mapWidth + 1; // width + '\n'
        }
    }

    // End of word/string
    m_window[windowSize - 1] = '\0';
}

void Window::Draw(Map& currentMap, std::vector<Entity*> allEntities)
{
    system("cls"); //clear

    currentMap.draw(m_window);

    const Spell* playerSpell = ((Player*)allEntities[0])->getSpell();
    if (playerSpell)
        playerSpell->drawRange(m_window, currentMap);

    for (int i = 0; i < allEntities.size(); ++i)
    {
        if (allEntities[i]->isAlive())
            allEntities[i]->draw(m_window, currentMap);
    }
    if (playerSpell)
        playerSpell->drawCursor(m_window, currentMap.getWidth());

    std::cout << m_window;
}
