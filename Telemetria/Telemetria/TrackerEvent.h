#pragma once
#include "EventData.h"
#include <string>

class TrackerEvent
{
protected:
	TrackerEvent(EventType type_, time_t timestamp_, int sessionID_, int playerID_);
	EventType _type;
	time_t _timestamp;
	int _sessionID;
	int _playerID;
public:
	virtual std::string toJSON() const;
};