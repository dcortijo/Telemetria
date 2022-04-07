#pragma once
#include "TrackerEvent.h"
class SessionStart : public TrackerEvent
{
public:
	SessionStart( time_t timestamp, int sessionID, int playerID);
};

