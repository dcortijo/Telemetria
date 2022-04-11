#include "SessionEnd.h"
SessionEnd::SessionEnd(time_t timestamp, int sessionID) :
	TrackerEvent(EventType::SessionEnd, timestamp, sessionID)
{
}