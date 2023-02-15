#include "pch.h"

namespace Profiler
{
	void BeginSession(std::string Profile)
	{
		Instrumentor::Get().BeginSession(Profile, Profile + ".json");
	}

	void EndSession()
	{
		Instrumentor::Get().EndSession();
	}
}
