#include "Player.h"
#include <conio.h>

E_PlayerAction Player::readPlayerInputs()
{
    char ch = _getch();

    // some people wanted to check this (cf ASCII table)
    if (ch >= 'A' && ch <= 'Z')
        ch -= 26;

    E_PlayerAction action;
    switch (ch)
    {
        case 'z': action = E_PlayerAction::Move_Up; break;
        case 's': action = E_PlayerAction::Move_Down; break;
        case 'q': action = E_PlayerAction::Move_Left; break;
        case 'd': action = E_PlayerAction::Move_Right; break;
        case ' ': action = E_PlayerAction::Attack; break;
        default: action = E_PlayerAction::None; break;
    }

    return action;
}

Vector2 Player::getDirection(E_PlayerAction action)
{
    return g_directions[(int)action - 1];
}

const Spell* Player::getSpell() const
{
    return nullptr;
}

void Player::onUpdate(Map& currentMap, std::vector<Entity*>& allEntities)
{
    E_PlayerAction playerAction;
    Vector2 dir;
    bool moved;
    do {
        playerAction = readPlayerInputs();

        if (playerAction == E_PlayerAction::Attack ||
            playerAction == E_PlayerAction::None)
            continue;
        
        dir = getDirection(playerAction);
        moved = move(dir, currentMap, allEntities);
    } while (!moved);
}
