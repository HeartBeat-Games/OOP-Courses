#pragma once
#include "Entity.h"
#include "Player.h"
#include "Vector2.h"
#include "IState.h"

class Mage : public virtual Player
{
	struct MoveState : public IState
	{
		// IState
		void onEnter(Entity* player) override;
		int onUpdate(Map& currentMap, Entity* player, std::vector<Entity*> allEntities) override;
		void onExit(Entity* player) override;

		friend class Mage;
	};

	struct SpellState : public IState
	{
		// IState
		void onEnter(Entity* player) override;
		int onUpdate(Map& currentMap, Entity* player, std::vector<Entity*> allEntities) override;
		void onExit(Entity* player) override;

		friend class Mage;
	};

	enum E_State {
		kMove = 0,
		kSpell,
		kEnd_Turn,
		kCount_State
	};

private:
	Spell m_spell;
	IState* m_states[E_State::kCount_State - 1];

public:
	Mage(const Vector2& position);
	~Mage();

	const Spell* getSpell() const override { return &m_spell; };
	void onUpdate(Map& currentMap, std::vector<Entity*>& allEntities) override;
};