#include "FilePersistence.h"
#include "TrackerEvent.h"

void FilePersistence::Send(TrackerEvent* event)
{
	eventQueue.push(event);
}

void FilePersistence::Flush()
{
	while (!eventQueue.empty()) {
		serializer->serialize(*eventQueue.front());
		eventQueue.pop();
	}
}
