#include "Entity.h"
#include "Swimmer.h"
#include "CollisionEvents.h"

Entity::Entity(const Vector2& position, E_CharacterType type)
    : m_pos(position), m_type(type)
{
}

void Entity::onCollision(Entity* other)
{
    takeDamage(other->getDamage());
}

bool Entity::checkMoveCollision(Vector2& newPos, std::vector<Entity*>& allEntities)
{
    for (int i = 0; i < allEntities.size(); ++i)
    {
        Entity* other = allEntities[i];

        // Collision with currently moving character ?
        if (other->isAlive() &&
            other->getPosition() == newPos)
        {
            if (other->getType() == m_type)
                return true; // Can't collide with the same character type
            else
            {
                CollisionEvents::getInstance()->addEvent(this, other);
            }
        }
    }
    return false;
}

bool Entity::move(Vector2& dir, Map& map, std::vector<Entity*>& allEntities)
{
    Vector2 newPos = m_pos;
    newPos += dir; // override + operator for less code

    // Borders check
    if (newPos.x < 0 || newPos.x >= map.getWidth() ||
        newPos.y < 0 || newPos.y >= map.getHeight())
        return false;

    Swimmer* swimmer = dynamic_cast<Swimmer*>(this);

    if (!(swimmer && map.getCellInfo(newPos).isSwimmable) &&
        !map.getCellInfo(newPos).isWalkable)
        return false;


    if (checkMoveCollision(newPos, allEntities))
        return false;

    m_pos = newPos;

    return true;
}

void Entity::takeDamage(int damage)
{
    m_life -= damage;
    if (m_life <= 0)
        m_isAlive = false;
}

void Entity::draw(char* window, Map& currentMap)
{
    int index = currentMap.get1DCell(m_pos);
    window[index + m_pos.y] = m_symbol;
}
