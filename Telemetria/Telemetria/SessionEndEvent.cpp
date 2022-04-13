#include "SessionEndEvent.h"

SessionEndEvent::SessionEndEvent(time_t timestamp, int sessionID) :
	TrackerEvent(EventType::SessionEnd, timestamp, sessionID)
{
}

std::string SessionEndEvent::toJSON() const
{
	std::string base = baseInfo();

	return "{ " + base + " } ]";	// Siempre sera el ultimo evento
}