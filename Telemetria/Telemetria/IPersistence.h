#pragma once
#include "ISerializer.h"
#include <queue>

class IPersistence
{
protected:
	/// <summary>
	/// Serializador de eventos
	/// </summary>
	ISerializer* serializer;
	
	/// <summary>
	/// Cola de eventos
	/// </summary>
	std::queue<TrackerEvent*> eventQueue;
public:
	IPersistence() = delete;
	IPersistence(const IPersistence&) = delete;
	IPersistence& operator= (const IPersistence&) = delete;
	IPersistence(IPersistence&&) = delete;
	IPersistence& operator= (IPersistence&&) = delete;
	virtual ~IPersistence() { delete serializer; }
	/// <summary>
	/// Envia el evento a la cola de eventos 
	/// </summary>
	virtual void Send(TrackerEvent* event) = 0;
	/// <summary>
	/// Vuelca los eventos tras serializarlos en "la persistencia" 
	/// </summary>
	virtual void Flush() = 0;
};