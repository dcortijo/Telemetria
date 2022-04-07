#include "JSONSerializer.h"
#include "TrackerEvent.h"

std::string JSONSerializer::serialize(const TrackerEvent& tracker)
{
	return tracker.toJSON();
}