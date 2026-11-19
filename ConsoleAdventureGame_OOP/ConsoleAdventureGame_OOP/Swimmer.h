#pragma once
#include "Map.h"
#include "Vector2.h"

class Swimmer
{
private:
	int m_oxygen;

public:
	int getOxygen() const { return m_oxygen; }

	void checkSwim(Map& currentMap, Vector2& position);
};

