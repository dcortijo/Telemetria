#include "SessionStartEvent.h"
#include "Tracker.h"
SessionStartEvent::SessionStartEvent(time_t timestamp):
	TrackerEvent( EventType::SessionStart,  timestamp)
{
}

std::string SessionStartEvent::toJSON() const
{
	std::string base = baseInfo();

	return "[ { " + base + " }, ";	// Siempre sera el primer evento
}