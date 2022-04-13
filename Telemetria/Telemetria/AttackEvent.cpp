#include "AttackEvent.h"

AttackEvent::AttackEvent(time_t timestamp, int sessionID, Characters character, Attacks attack, Players playerId) :
	TrackerEvent(EventType::Attack, timestamp, sessionID), _character(character), _attack(attack), _playerID(playerId)
{
}

std::string AttackEvent::toJSON() const
{
	std::string base = baseInfo();

	char buffer[1000];
	std::snprintf(buffer, 1000,
		"\"Player\": %d, \"Character\": %d, \"Attack\": %d",
		_playerID, _character, _attack);
	std::string specific(buffer);

	return "{ " + base + ", " + specific + " }, ";
}
