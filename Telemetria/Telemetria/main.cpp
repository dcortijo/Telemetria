#include "Tracker.h"
#include "ReceiveDamageEvent.h"
#include "AbilityEvent.h"
#include "SessionStartEvent.h"
#include "SessionEndEvent.h"
#include <time.h>

int main() {
	Tracker::instance()->init();
	TrackerEvent* even = new SessionStartEvent(0);
	Tracker::instance()->trackEvent(even);
	Tracker::instance()->flushPersistence();
	even = new ReceiveDamageEvent(0, 1,  Characters::F10R, Players::PLAYER1, Attacks::NoAttack, Abilities::AcidSplit);
	Tracker::instance()->trackEvent(even);
	Tracker::instance()->flushPersistence();
	even = new AbilityEvent(0,  Characters::MKWH00P, Abilities::VampiricStrike, Players::PLAYER2);
	Tracker::instance()->trackEvent(even);
	Tracker::instance()->flushPersistence();
	even = new SessionEndEvent(0);
	Tracker::instance()->trackEvent(even);
	Tracker::instance()->flushPersistence();
	return 0;
}