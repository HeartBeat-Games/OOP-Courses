#pragma once
#include<string>
#include "Map.h"
#include "Entity.h"

class Game
{
private:
	static Game*					m_instance;
	inline static const std::string	m_levelDirectoryPath = "levels";
	inline static const std::string	m_levelRootPath = m_levelDirectoryPath + "/level";

	char*					m_window = nullptr;
	Map						m_currentMap;
	std::vector<Entity*>	m_entities;
	int						m_currentLevel = 0;

private:
	Game() {}
	void loadCurrentLevel();
	void generateEntities();
	void collisionEventsProcess();
	void gameOver();

public:
	static Game* getInstance();
	static void freeInstance();

	void run();
};