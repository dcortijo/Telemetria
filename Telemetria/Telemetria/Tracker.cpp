#include "Tracker.h"
#include "FilePersistence.h"
#include "HashGenerator.h"
Tracker::~Tracker() 
{
	delete persistenceObject;
}

void Tracker::init() 
{
	persistenceObject = new FilePersistence();
	persistenceObject->init();

	currSession = generateSessionID();
}

void Tracker::trackEvent(TrackerEvent* event)
{
	persistenceObject->send(event);
}

void Tracker::flushPersistence()
{
	persistenceObject->flush();
}