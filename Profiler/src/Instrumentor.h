#pragma once
#include "iostream"
#include <fstream>
#include <string>

namespace Profiler
{
	struct ProfileResult
	{
		std::string Name;
		long long Start, End;
		uint32_t ThreadID;
	};

	struct InstrumentationSession
	{
		std::string Name;
	};

	class Instrumentor
	{
	private:
		InstrumentationSession* m_CurrentSession;
		std::ofstream m_OutputStream;
		int m_ProfileCount;
	public:
		Instrumentor();

		void BeginSession(const std::string& name, const std::string& filepath = "results.json");

		void EndSession();

		void WriteProfile(const ProfileResult& result);

		void WriteHeader();

		void WriteFooter();

		static Instrumentor& Get();
	};
}
