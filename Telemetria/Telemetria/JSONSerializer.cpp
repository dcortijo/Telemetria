#include "JSONSerializer.h"
#include "TrackerEvent.h"
#include "json.hpp"

using namespace nlohmann;

std::string JSONSerializer::serialize(const TrackerEvent& tracker)
{
	return tracker.toJSON();
}