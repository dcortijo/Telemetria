#include "Tracker.h"
#include "FilePersistence.h"

Tracker::~Tracker() 
{
	delete persistenceObject;
}

void Tracker::init() 
{
	persistenceObject = new FilePersistence();
	persistenceObject->init();
}

void Tracker::trackEvent(TrackerEvent* event)
{
	persistenceObject->send(event);
}

void Tracker::flushPersistence()
{
	persistenceObject->flush();
}