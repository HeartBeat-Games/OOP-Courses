#include "HeadlessZombie.h"

#include <random>

Vector2 HeadlessZombie::getDirection(Entity* player)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> distrib(0, 3);

    return g_directions[distrib(gen)];
}
