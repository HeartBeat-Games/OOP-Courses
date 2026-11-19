#include "Swimmer.h"

void Swimmer::checkSwim(Map& currentMap, Vector2& position)
{
	if (currentMap.getCellInfo(position).isSwimmable)
		m_oxygen--;
	else
		m_oxygen = 2;
}
