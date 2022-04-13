#include "FilePersistence.h"
#include "TrackerEvent.h"
#include "JSONSerializer.h"
#include <iostream>

FilePersistence::~FilePersistence()
{
	delete serializer;
}

void FilePersistence::init()
{
	serializer = new JSONSerializer();
}

void FilePersistence::send(TrackerEvent* event)
{
	eventQueue.push(event);
}

void FilePersistence::flush()
{
	while (!eventQueue.empty()) {
		TrackerEvent* even = eventQueue.front();
		std::string serialized = serializer->serialize(*even);
		//TODO Escribir aqui en archivo
		std::cout << serialized << std::endl;
		eventQueue.pop();
		delete even;
	}
}
