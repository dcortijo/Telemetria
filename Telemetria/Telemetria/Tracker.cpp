#include "Tracker.h"

void Tracker::trackEvent(TrackerEvent* event)
{
	persistenceObject->Send(event);
}