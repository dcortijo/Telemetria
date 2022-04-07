#pragma once
#include <list>

#include "Singleton.h"
#include "ITrackerAsset.h"
#include "IPersistence.h"

class Tracker: public Singleton<Tracker>
{
	friend Singleton<Tracker>;
private:
	IPersistence* persistenceObject;
public:
	void trackEvent(TrackerEvent* event);
};