#pragma once
#include "EventData.h"
#include <string>

class TrackerEvent
{
protected:
	EventType type;
	int timestamp;
	int sessionID;
	int userID;
	int gameID;
public:
	TrackerEvent() {}
	virtual std::string toCSV() const = 0;
	virtual std::string toJSON() const = 0;
};