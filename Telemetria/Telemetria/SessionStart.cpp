#include "SessionStart.h"
SessionStart::SessionStart(time_t timestamp, int sessionID, int playerID): 
	TrackerEvent( EventType::SessionStart,  timestamp,  sessionID, playerID)
{
}