#include "CollisionEvents.h"
#include "Entity.h"

CollisionEvents* CollisionEvents::getInstance()
{
	static CollisionEvents instance;
	return &instance;
}

void CollisionEvents::addEvent(Entity* entity1, Entity* entity2)
{
	m_events.push_back(CollisionEvent{
		.entity1 = entity1,
		.entity2 = entity2
		});
}

const CollisionEvent* CollisionEvents::getAllEvents() const
{
	return m_events.data();
}

void CollisionEvents::clearEvents()
{
	m_events.clear();
}

size_t CollisionEvents::getEventCount() const
{
	return m_events.size();
}
