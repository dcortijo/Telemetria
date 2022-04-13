#include "RoundStartEvent.h"

RoundStartEvent::RoundStartEvent(time_t timestamp, int sessionID, Characters characters[NUM_PLAYERS], Abilities abilities[NUM_PLAYERS][NUM_ABILITIES]) :
	TrackerEvent(EventType::RoundStart, timestamp, sessionID)
{
	memcpy(_characters, characters, sizeof(Characters) * NUM_PLAYERS);
	memcpy(_abilities, abilities, sizeof(Abilities) * NUM_PLAYERS * NUM_ABILITIES);
}

std::string RoundStartEvent::toJSON() const
{
	std::string base = baseInfo();

	char buffer[1000];
	std::snprintf(buffer, 1000,
		"\"Character 1\": %d, \"Abilities 1-1\": %d, \"Abilities 1-2\": %d, \"Character 2\": %d, \"Abilities 2-1\": %d, \"Abilities 2-2\": %d",
		_characters[0], _abilities[0][0], _abilities[0][1], _characters[1], _abilities[1][0], _abilities[1][1]);
	std::string specific(buffer);

	return "{ " + base + ", " + specific + " }, ";
}
