#pragma once
#include "Player.h"
#include "Vector2.h"

class Warrior : public virtual Player
{
public:
	Warrior(const Vector2& position) : Player(position) { m_life = 3; m_damage = 1; }
};