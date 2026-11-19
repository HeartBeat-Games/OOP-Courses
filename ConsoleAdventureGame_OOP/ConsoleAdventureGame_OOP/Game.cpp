#include "Game.h"

#include <filesystem>
#include <iostream>

#include "Window.h"

#include "Warrior.h"
#include "Mage.h"
#include "WarriorMage.h"

#include "Zombie.h"
#include "HeadlessZombie.h"
#include "ZombieSwimmer.h"

#include "CollisionEvents.h"
#include <random>

namespace fs = std::filesystem;

Game* Game::m_instance = nullptr;

void Game::loadCurrentLevel()
{
    std::ifstream levelFile;

    std::string levelPath =
        m_levelRootPath + std::to_string(m_currentLevel) + ".txt";

    for (const auto& entry : fs::directory_iterator(m_levelDirectoryPath))
        if (entry.is_regular_file())
        {
            if (entry.path() == levelPath)
            {
                levelFile.open(entry.path());
                break;
            }
        }

    m_currentMap.loadLevel(levelFile);

    generateEntities();
    Window::getInstance()->InitializeWindow(m_currentMap);
    Window::getInstance()->Draw(m_currentMap, m_entities);
}

void Game::generateEntities()
{
    m_entities.clear();

    auto& spawns = m_currentMap.getCharacterSpawns();

    m_entities.push_back(new WarriorMage(spawns[0]));

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> distrib(0, 2);

    for (int i = 1; i < spawns.size(); ++i)
    {
        const Vector2& spawnPosition = spawns[i];
        int type = distrib(gen);
        switch (type)
        {
            case 0: m_entities.push_back(new Zombie(spawnPosition)); break;
            case 1: m_entities.push_back(new HeadlessZombie(spawnPosition)); break;
            case 2: m_entities.push_back(new ZombieSwimmer(spawnPosition)); break;
        }
    }
}

void Game::collisionEventsProcess()
{
    CollisionEvents* eventManager = CollisionEvents::getInstance();
    const CollisionEvent* events = eventManager->getAllEvents();
    for (int i = 0; i < eventManager->getEventCount(); ++i)
    {
        const CollisionEvent& event = events[i];
        event.entity1->onCollision(event.entity2);
        event.entity2->onCollision(event.entity1);
    }
    CollisionEvents::getInstance()->clearEvents();
}

void Game::gameOver()
{
    system("cls"); //clear
    if (m_entities[0]->isAlive())
        std::cout << "VICTOIRE !" << std::endl;
    else
        std::cout << "DEFAITE !" << std::endl;
}

Game* Game::getInstance()
{
    if (m_instance == nullptr)
        m_instance = new Game();

    return m_instance;
}

void Game::freeInstance()
{
    delete m_instance;
}

void Game::run()
{
    loadCurrentLevel();

    do {
        while (m_entities[0]->isAlive() &&
            !m_currentMap.isExit(m_entities[0]->getPosition()))
        {
            for (int i = 0; i < m_entities.size(); ++i)
                if (m_entities[i]->isAlive())
                    m_entities[i]->onUpdate(m_currentMap, m_entities);

            collisionEventsProcess();

            Window::getInstance()->Draw(m_currentMap, m_entities);
        }
        ++m_currentLevel;
        loadCurrentLevel();

    } while (m_currentLevel < 2);

    gameOver();
}