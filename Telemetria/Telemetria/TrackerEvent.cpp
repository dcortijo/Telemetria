#include "TrackerEvent.h"
#include "Tracker.h"
TrackerEvent::TrackerEvent(EventType type, time_t timestamp, std::string sessionID)
	: _type(type), _timestamp(timestamp), _sessionID(sessionID)
{
}

TrackerEvent::TrackerEvent(EventType type, time_t timestamp):
	_type(type), _timestamp(timestamp), _sessionID(Tracker::instance()->getSessionID())
{
}

std::string TrackerEvent::toJSON() const
{
	return "{ " + baseInfo() + " }";
}

std::string TrackerEvent::baseInfo() const
{
	char buffer[1000];
	std::snprintf(buffer, 1000,
		"\"type\": %d, \"time\": %d, \"session\": %s", _type, _timestamp, _sessionID.c_str());
	return std::string(buffer);
}
