#pragma once
#include <vector>

#include "Vector2.h"
#include "Map.h"

class Entity;

class Spell
{
	bool	m_isVisible = false;

	Vector2 m_origin = Vector2{};
	Vector2 m_cursor = Vector2{};

	int		m_range = 0;
	int		m_damage = 0;

public:
	void initializeSpell(Entity* player);
	void stopSpell();
	bool moveCursor(Vector2& dir, Map& currentMap);
	void spellDamage(std::vector<Entity*> allEntities);
	void drawRange(char* window, Map& currentMap) const;
	void drawCursor(char* window, size_t mapWidth) const;
};