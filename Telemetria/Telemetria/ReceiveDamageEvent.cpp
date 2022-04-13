#include "ReceiveDamageEvent.h"

ReceiveDamageEvent::ReceiveDamageEvent(time_t timestamp, int sessionID, int damage, Characters character, Players player, Attacks attack, Abilities ability):
TrackerEvent(EventType::ReceiveDamage, timestamp, sessionID), _damage(damage), _character(character), _player(player), _attack(attack), _ability(ability)
{
}

std::string ReceiveDamageEvent::toJSON() const
{
	std::string base = baseInfo();

	char buffer[1000];
	std::snprintf(buffer, 1000,
		"\"Damage\": %d, \"Character\": %d, \"Player\": %d, \"Attack\": %d, \"Ability\": %d",
		_damage, _character, _player, _attack, _ability);
	std::string specific(buffer);

	return "{ " + base + ", " + specific + " }, ";
}