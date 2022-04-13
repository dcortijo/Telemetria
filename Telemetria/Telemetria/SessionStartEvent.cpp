#include "SessionStartEvent.h"

SessionStartEvent::SessionStartEvent(time_t timestamp, int sessionID):
	TrackerEvent( EventType::SessionStart,  timestamp,  sessionID)
{
}

std::string SessionStartEvent::toJSON() const
{
	std::string base = baseInfo();

	return "[ { " + base + " }, ";	// Siempre sera el primer evento
}