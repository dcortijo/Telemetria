#include "TrackerEvent.h"

TrackerEvent::TrackerEvent(EventType type, time_t timestamp, int sessionID, int playerID)
	: _type(type), _timestamp(timestamp), _sessionID(sessionID), _playerID(playerID)
{
}

std::string TrackerEvent::toJSON() const
{
	char buffer[1000];
	std::snprintf(buffer, 1000,
		"{ \"type\": $d\n\"time:\": $d\n\"session\": $d\n\"player\": $d }", _type, _timestamp, _sessionID, _playerID);
	return std::string(buffer);
}
