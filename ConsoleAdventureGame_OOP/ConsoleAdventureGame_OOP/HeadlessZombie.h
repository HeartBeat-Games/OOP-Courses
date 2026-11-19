#pragma once
#include "Enemy.h"

class HeadlessZombie : public Enemy
{
public:
	HeadlessZombie(const Vector2& position) : Enemy(position) {}

private:
	Vector2 getDirection(Entity* player) override;
};