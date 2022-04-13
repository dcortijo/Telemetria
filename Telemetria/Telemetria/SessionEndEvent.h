#pragma once
#include "TrackerEvent.h"

class SessionEndEvent :  public TrackerEvent
{
public:
	SessionEndEvent(time_t timestamp, int sessionID);
	std::string toJSON() const override;
};

