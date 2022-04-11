#pragma once
#include "TrackerEvent.h"

class RoundStart :
    public TrackerEvent
{
public:
	RoundStart(time_t timestamp, int sessionID, Characters characters[NUM_PLAYERS], Abilities abilities[NUM_PLAYERS][NUM_ABILITIES]);
	std::string toJSON() const override;
private:
	Characters _characters[NUM_PLAYERS];
	Abilities _abilities[NUM_PLAYERS][NUM_ABILITIES];
};

