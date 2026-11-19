#pragma once
#include "Warrior.h"
#include "Mage.h"

class WarriorMage : public Warrior, public Mage
{
public:
	WarriorMage(const Vector2& position);

	const Spell* getSpell() const override;
	void onUpdate(Map& currentMap, std::vector<Entity*>& allEntities) override;
};