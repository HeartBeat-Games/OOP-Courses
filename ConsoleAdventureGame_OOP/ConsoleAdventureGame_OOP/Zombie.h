#pragma once
#include "Enemy.h"

class Zombie : public Enemy
{
public:
	Zombie(const Vector2& position) : Enemy(position) {}

private:
	Vector2 getDirection(Entity* player) override;
};