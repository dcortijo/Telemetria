#pragma once
#include "TrackerEvent.h"

class ReceiveHit :
	public TrackerEvent
{
public:
	ReceiveHit(time_t timestamp, int sessionID, int damage, Characters character, Players player, Attacks attack, Abilities ability);
	std::string toJSON() const override;
private:
	Characters _character;
	Players _player;
	int _damage;
	Attacks _attack;
	Abilities _ability;
};


