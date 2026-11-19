#include "Spell.h"
#include "Entity.h"

void Spell::initializeSpell(Entity* player)
{
	m_origin = player->getPosition();
	m_cursor = m_origin;
	m_damage = 3;
	m_range = 1;

	m_isVisible = true;
}

void Spell::stopSpell()
{
	m_isVisible = false;
}

bool Spell::moveCursor(Vector2& dir, Map& currentMap)
{
	Vector2 newPos = m_cursor;
	newPos += dir;

	int distanceX = abs(newPos.x - m_origin.x);
	int distanceY = abs(newPos.y - m_origin.y);

	if (distanceX <= m_range &&
		distanceY <= m_range &&
		currentMap.getCellInfo(newPos).isWalkable)
	{
		m_cursor = newPos;
		return true;
	}
	return false;
}

void Spell::spellDamage(std::vector<Entity*> allEntities)
{
	for (int i = 1; i < allEntities.size(); ++i)
		if (allEntities[i]->getPosition() == m_cursor)
			allEntities[i]->takeDamage(m_damage);
}

void Spell::drawRange(char* window, Map& currentMap) const
{
	size_t mapWidth = currentMap.getWidth();
	size_t mapHeight = currentMap.getHeight();

	if (m_isVisible)
		for (int y = (m_origin.y - m_range);
			y <= (m_origin.y + m_range); ++y)

		for (int x = (m_origin.x - m_range);
			x <= (m_origin.x + m_range); ++x)
	{
		if (y < 0 || y >= mapHeight ||
			x < 0 || x >= mapWidth)
			continue;

		if (!currentMap.getCellInfo({ x, y }).isWalkable)
			continue;

		int index = y * mapWidth + x;
		window[index + y] = '*';
	}
}

void Spell::drawCursor(char* window, size_t mapWidth) const
{
	//Spell cursor
	if (m_isVisible)
	{
		int index = m_cursor.y * mapWidth + m_cursor.x;
		window[index + m_cursor.y] = '^';
	}
}
