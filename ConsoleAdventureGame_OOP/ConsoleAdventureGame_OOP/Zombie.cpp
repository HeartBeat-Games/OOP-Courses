#include "Zombie.h"

Vector2 Zombie::getDirection(Entity* player)
{
	Vector2 dir;
	const Vector2& playerPos = player->getPosition();

	if (m_pos.y != playerPos.y)
		dir.y = m_pos.y > playerPos.y ? -1 : 1;
	else
		dir.x = m_pos.x > playerPos.x ? -1 : 1;

	return dir;
}