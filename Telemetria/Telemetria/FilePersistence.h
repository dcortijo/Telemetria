#pragma once
#include "IPersistence.h"

class FilePersistence : public IPersistence
{
	// Inherited via IPersistence
	virtual void init() override;
	virtual void send(TrackerEvent* event) override;
	virtual void flush() override;
};

