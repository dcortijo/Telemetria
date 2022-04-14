#include "SessionEndEvent.h"

SessionEndEvent::SessionEndEvent(time_t timestamp) :
	TrackerEvent(EventType::SessionEnd, timestamp)
{
}

std::string SessionEndEvent::toJSON() const
{
	std::string base = baseInfo();

	return "{ " + base + " } \n]";	// Siempre sera el ultimo evento
}