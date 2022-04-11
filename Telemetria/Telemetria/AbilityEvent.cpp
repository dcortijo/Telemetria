#include "AbilityEvent.h"

AbilityEvent::AbilityEvent(time_t timestamp, int sessionID, Characters character, Abilities ability, Players playerId) :
	TrackerEvent(EventType::RoundStart, timestamp, sessionID), _character(character), _ability(ability), _playerID(playerId)
{
}

std::string AbilityEvent::toJSON() const
{
	std::string base = baseInfo();

	char buffer[1000];
	std::snprintf(buffer, 1000,
		"\"Player\": $d \"Character\": $d \"Ability\": $d",
		_playerID, _character, _ability);
	std::string specific(buffer);

	return "{ " + base + " " + specific + " }";
}
