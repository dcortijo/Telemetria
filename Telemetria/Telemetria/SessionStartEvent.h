#pragma once
#include "TrackerEvent.h"

class SessionStartEvent : public TrackerEvent
{
public:
	SessionStartEvent( time_t timestamp, int sessionID);
	std::string toJSON() const override;
};

