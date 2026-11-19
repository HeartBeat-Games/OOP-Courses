#include "ZombieSwimmer.h"

ZombieSwimmer::ZombieSwimmer(const Vector2& position)
	: Zombie(position)
{
	m_symbol = 'S';
}

void ZombieSwimmer::onUpdate(Map& currentMap, std::vector<Entity*>& allEntities)
{
	Enemy::onUpdate(currentMap, allEntities);
	checkSwim(currentMap, m_pos);
	if (getOxygen() < 0)
	{
		m_life = 0;
		m_isAlive = false;
	}
}
