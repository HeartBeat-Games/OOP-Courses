#include "Mage.h"
#include "Window.h"

void Mage::MoveState::onEnter(Entity* player) {}

int Mage::MoveState::onUpdate(Map& currentMap, Entity* player, std::vector<Entity*> allEntities)
{
    Mage* mage = dynamic_cast<Mage*>(player);
    E_PlayerAction playerAction;
    Vector2 dir;
    bool moved;
    do {
        playerAction = mage->readPlayerInputs();
        
        if (playerAction == E_PlayerAction::None)
            continue;
        if (playerAction == E_PlayerAction::Attack)
            return E_State::kSpell;

        dir = mage->getDirection(playerAction);
        moved = mage->move(dir, currentMap, allEntities);

    } while (!moved);

    return E_State::kEnd_Turn;
}

void Mage::MoveState::onExit(Entity* player) {}

void Mage::SpellState::onEnter(Entity* player)
{
    Mage* mage = dynamic_cast<Mage*>(player);
    mage->m_spell.initializeSpell(mage);
}

int Mage::SpellState::onUpdate(Map& currentMap, Entity* player, std::vector<Entity*> allEntities)
{
    Window::getInstance()->Draw(currentMap, allEntities);

    Mage* mage = dynamic_cast<Mage*>(player);
    E_PlayerAction playerAction;
    Vector2 dir;
    bool moved = false;

    while (true)
    {
        do {
            playerAction = mage->readPlayerInputs();

            if (playerAction == E_PlayerAction::None)
                continue;
            if (playerAction == E_PlayerAction::Attack)
            {
                mage->m_spell.spellDamage(allEntities);
                return E_State::kEnd_Turn;
            }

            dir = mage->getDirection(playerAction);
            moved = mage->m_spell.moveCursor(dir, currentMap);
        } while (!moved);

        // I wanted to compact everything to be simple to read. And not modify the original code much.
        // So I needed to redraw the window here... And I ended up creating a Window singleton class.
        // Don't think it's a good thing to do, please !
        Window::getInstance()->Draw(currentMap, allEntities);
    }
}

void Mage::SpellState::onExit(Entity* player)
{
    Mage* mage = dynamic_cast<Mage*>(player);
    mage->m_spell.stopSpell();
}

Mage::Mage(const Vector2& position)
    : Player(position)
{
    m_states[E_State::kMove] = new MoveState();
    m_states[E_State::kSpell] = new SpellState();
}

Mage::~Mage()
{
    delete m_states[E_State::kMove];
    delete m_states[E_State::kSpell];
}

void Mage::onUpdate(Map& currentMap, std::vector<Entity*>& allEntities)
{
    E_State currentState = E_State::kMove;
    E_State nextState;

    m_states[currentState]->onEnter(this);
    do {
        nextState = (E_State)m_states[currentState]->onUpdate(
            currentMap, this, allEntities
        );
        if (nextState != currentState)
        {
            m_states[currentState]->onExit(this);
            currentState = nextState;
            
            if (currentState != E_State::kEnd_Turn)
                m_states[currentState]->onEnter(this);
        }
        
    } while (currentState != E_State::kEnd_Turn);
}
