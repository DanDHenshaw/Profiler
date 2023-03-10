#pragma once

#include <chrono>

namespace Profiler
{
	static thread_local int sm_iNestCount;

	class InstrumentationTimer
	{
	public:
		InstrumentationTimer(const char* name);
		~InstrumentationTimer();

		void Stop();

	private:
		const char* m_Name;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
		bool m_Stopped;
	};
}