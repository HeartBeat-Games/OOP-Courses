#pragma once
#include <vector>

#include "Entity.h"
#include "Map.h"

class Window
{
	char* m_window = nullptr;

public:
	static Window* getInstance();

	void InitializeWindow(Map& currentMap);
	void Draw(Map& currentMap, std::vector<Entity*> allEntities);
};

