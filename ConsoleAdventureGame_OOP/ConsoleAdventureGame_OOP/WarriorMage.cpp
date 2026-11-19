#include "WarriorMage.h"

WarriorMage::WarriorMage(const Vector2& position)
	: Player(position), Warrior(position), Mage(position)
{
}

const Spell* WarriorMage::getSpell() const
{
	return Mage::getSpell();
}

void WarriorMage::onUpdate(Map& currentMap, std::vector<Entity*>& allEntities)
{
	Mage::onUpdate(currentMap, allEntities);
}