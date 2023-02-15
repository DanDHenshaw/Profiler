#pragma once

#include "Instrumentor.h"
#include "Timer.h"

namespace Profiler
{
	void BeginSession(std::string Profile);

	void EndSession();
}