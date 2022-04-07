#pragma once
#include "TrackerEvent.h"
class SessionEnd :  public TrackerEvent
{
public:
	SessionEnd(time_t timestamp, int sessionID, int playerID);
};

