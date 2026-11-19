#pragma once
#include "Entity.h"
#include "Spell.h"

enum E_PlayerAction
{
    None = 0,
    Move_Up,
    Move_Down,
    Move_Left,
    Move_Right,
    Attack
};

class Player : public Entity
{
protected:
	E_PlayerAction readPlayerInputs();
	Vector2 getDirection(E_PlayerAction action);

public:
    Player(const Vector2& position) : Entity(position, E_CharacterType::Player) { m_symbol = 'H'; m_damage = 0; }

    virtual const Spell* getSpell() const; // for drawing

	// Entity override
    virtual void onUpdate(Map& currentMap, std::vector<Entity*>& allEntities) override;
};

