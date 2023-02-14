#include "pch.h"

#include <iostream>
#include <memory>
#include <thread>

namespace Profiler
{
	InstrumentationTimer::InstrumentationTimer(const char* name)
		: m_Name(name), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();

		++sm_iNestCount;
	}

	InstrumentationTimer::~InstrumentationTimer()
	{
		if(!m_Stopped)
			Stop();
	}

	void InstrumentationTimer::Stop()
	{
		std::chrono::time_point<std::chrono::steady_clock> endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count() + sm_iNestCount;
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
		Instrumentor::Get().WriteProfile({ m_Name, start, end, threadID });
		--sm_iNestCount;

		m_Stopped = true;
	}
}
