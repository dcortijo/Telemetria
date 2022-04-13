#pragma once
#include <list>

#include "Singleton.h"
#include "IPersistence.h"

class Tracker: public Singleton<Tracker>
{
	friend Singleton<Tracker>;
private:
	IPersistence* persistenceObject;
	char currSession[24];	// usamos puid :3
public:
	~Tracker();
	void init();
	void trackEvent(TrackerEvent* event);
	void flushPersistence();
};