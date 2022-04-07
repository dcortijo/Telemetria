#include "SessionEnd.h"
SessionEnd::SessionEnd(time_t timestamp, int sessionID, int playerID) :
	TrackerEvent(EventType::SessionEnd, timestamp, sessionID, playerID)
{
}