#include "TrackerEvent.h"

TrackerEvent::TrackerEvent(EventType type, time_t timestamp, int sessionID)
	: _type(type), _timestamp(timestamp), _sessionID(sessionID)
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
		"\"type\": $d\n\"time\": $d\n\"session\": $d\n", _type, _timestamp, _sessionID);
	return std::string(buffer);
}
