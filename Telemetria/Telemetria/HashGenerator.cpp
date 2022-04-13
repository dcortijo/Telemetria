#include "HashGenerator.h"
#include <windows.h>
#include <sstream>
#include <processthreadsapi.h>
#include <chrono>
#include <iostream>

/// <summary>
/// Para generar la id de sesion utilizamos el pid y el tiempo
/// </summary>
/// <returns> la id de sesion</returns>
std::string generateSessionID() {

	const auto p1 = std::chrono::system_clock::now();
	time_t timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
		p1.time_since_epoch()).count();
	DWORD pid = GetCurrentProcessId();
	std::string bytes = std::to_string(pid);
	bytes += std::to_string(timestamp);

	static char chars[] = "0123456789ABCDEF";
	std::stringstream stream;

	auto size = bytes.size();
	for (unsigned long i = 0; i < size; ++i) {
		unsigned char ch = ~((unsigned char)((unsigned short)bytes[i] +
			(unsigned short)bytes[(i + 1) % size] +
			(unsigned short)bytes[(i + 2) % size] +
			(unsigned short)bytes[(i + 3) % size])) * (i + 1);

		stream << chars[(ch >> 4) & 0x0F] << chars[ch & 0x0F];
	}

	return stream.str();
}
