#include "Enemy.h"

void Enemy::onUpdate(Map& currentMap, std::vector<Entity*>& allEntities)
{
    Vector2 dir;
    bool moved = false;
    int maxTry = 10; // Could be blocked by the map and other ennemies
    do {
        dir = getDirection(allEntities[0]);
        moved = move(dir, currentMap, allEntities);
        maxTry--;
    } while (!moved && maxTry > 0);
}
