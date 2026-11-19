#pragma once
#include "Vector2.h"
#include "Map.h"

static const Vector2 g_directions[4] = {
    {0,-1},  // Up
    {0, 1},  // Down
    {-1, 0}, // Left
    {1, 0}   // Right
};

class Entity
{
protected:
    enum E_CharacterType {
        Player = 0,
        Enemy,
        CharacterType_Count
    };

protected:
    E_CharacterType m_type = E_CharacterType::Enemy;
    Vector2         m_pos = Vector2{};
    bool            m_isAlive = true;

    int             m_life = 1;
    int             m_damage = 1;
    char            m_symbol = '#';

protected:
    Entity(const Vector2& position, E_CharacterType type);
    bool checkMoveCollision(Vector2& newPos, std::vector<Entity*>& allEntities);
    bool move(Vector2& dir, Map& map, std::vector<Entity*>& allEntities);

public:
    E_CharacterType getType() { return m_type; }
    bool isAlive() const { return m_isAlive; }
    Vector2 getPosition() const { return m_pos; }
    int getDamage() { return m_damage; }

    virtual void onCollision(Entity* other);
    void takeDamage(int damage);

    void draw(char* window, Map& currentMap);
    virtual void onUpdate(Map& currentMap, std::vector<Entity*>& allEntities) = 0;
};