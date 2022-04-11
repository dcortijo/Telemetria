#include "SessionStart.h"
SessionStart::SessionStart(time_t timestamp, int sessionID): 
	TrackerEvent( EventType::SessionStart,  timestamp,  sessionID)
{
}