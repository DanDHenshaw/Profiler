#include "pch.h"

namespace Profiler
{
	void BeginSession(std::string Profile)
	{
		Instrumentor::Get().BeginSession(Profile);
	}

	void EndSession()
	{
		Instrumentor::Get().EndSession();
	}
}
