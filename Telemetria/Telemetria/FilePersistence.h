#pragma once
#include "IPersistence.h"
class FilePersistence : public IPersistence
{
	// Inherited via IPersistence
	virtual void Send(TrackerEvent* event) override;
	virtual void Flush() override;
};

