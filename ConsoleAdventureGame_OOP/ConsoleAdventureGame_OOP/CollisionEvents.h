#pragma once
#include <vector>

class Entity;

struct CollisionEvent
{
	Entity* entity1;
	Entity* entity2;
};

class CollisionEvents
{
private:
	std::vector<CollisionEvent> m_events;

private:
	CollisionEvents() {}

public:
	static CollisionEvents* getInstance();

	void addEvent(Entity* entity1, Entity* entity2);
	const CollisionEvent* getAllEvents() const;
	void clearEvents();
	size_t getEventCount() const;
};