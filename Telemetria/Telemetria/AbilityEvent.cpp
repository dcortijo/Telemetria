#include "AbilityEvent.h"

AbilityEvent::AbilityEvent(time_t timestamp, Characters character, Abilities ability, Players playerId) :
	TrackerEvent(EventType::Ability, timestamp), _character(character), _ability(ability), _playerID(playerId)
{
}

std::string AbilityEvent::toJSON() const
{
	std::string base = baseInfo();

	char buffer[1000];
	std::snprintf(buffer, 1000,
		"\"Player\": %d, \"Character\": %d, \"Ability\": %d",
		_playerID, _character, _ability);
	std::string specific(buffer);

	return "{ " + base + ", " + specific + " }, ";
}
