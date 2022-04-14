#include "FilePersistence.h"
#include "TrackerEvent.h"
#include "JSONSerializer.h"
#include "Tracker.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <exception>
#include <sys/stat.h>


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
	struct stat pepis;
	if (stat("output", &pepis) != 0) {	// Creamos el directorio si no existe
		if (_mkdir("output") != 0)	
			throw "Could not make output directory";
	}

	std::fstream myfile;
	myfile.open("output/" + Tracker::instance()->getSessionID() + ".json", std::fstream::app | std::fstream::out);	// Abrimos o creamos el archivo

	if (myfile.is_open())
	{
		while (!eventQueue.empty()) {
			TrackerEvent* even = eventQueue.front();
			std::string serialized = serializer->serialize(*even) + "\n";
			myfile.write(serialized.c_str(), serialized.length());
			eventQueue.pop();
			delete even;
		}

		myfile.close();
	}
	else throw "Could not make output file";
}
