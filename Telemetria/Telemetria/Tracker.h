#pragma once
#include <list>

#include "Singleton.h"
#include "IPersistence.h"

class Tracker: public Singleton<Tracker>
{
	friend Singleton<Tracker>;
private:
	IPersistence* persistenceObject;
public:
	void init();
	void trackEvent(TrackerEvent* event);
	void flushPersistence();
};