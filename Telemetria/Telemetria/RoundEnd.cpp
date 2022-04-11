#include "RoundEnd.h"

RoundEnd::RoundEnd(time_t timestamp, int sessionID, Characters characters[NUM_PLAYERS], Characters winner) :
	TrackerEvent(EventType::RoundEnd, timestamp, sessionID), _winner(winner)
{
	memcpy(_characters, characters, sizeof(Characters) * NUM_PLAYERS);
}

std::string RoundEnd::toJSON() const
{
	std::string base = baseInfo();

	char buffer[1000];
	std::snprintf(buffer, 1000,
		"\"Character 1\": $d \"Character 2\": $d \"Winner\": $d ",
		_characters[0],  _characters[1], _winner);
	std::string specific(buffer);

	return "{ " + base + specific + " }";
}