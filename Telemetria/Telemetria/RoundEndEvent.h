#pragma once
#include "TrackerEvent.h"

class RoundEndEvent :
    public TrackerEvent
{
public:
	RoundEndEvent(time_t timestamp, int sessionID, Characters characters[NUM_PLAYERS], Characters winner);
	std::string toJSON() const override;
private:
	Characters _characters[NUM_PLAYERS];
	Characters _winner;
};

