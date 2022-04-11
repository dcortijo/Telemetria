#pragma once
#include "EventData.h"
#include <string>

class TrackerEvent
{
protected:
	TrackerEvent(EventType type_, time_t timestamp_, int sessionID_);
	EventType _type;
	time_t _timestamp;
	int _sessionID;
public:
	virtual std::string toJSON() const;
	std::string baseInfo() const;
};