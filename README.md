C++ Profiler
==========
Setup:
----------------------------
- Download the Profiler.zip [here](https://github.com/DanDHenshaw/Profiler/releases).
- Extract the `include` and `lib` folders into your VS Studio solution directory.
- Open your projects properties:
  - Navigate to `C/C++ > Additional Include Directoires` and link the `include` folder path.
  - Navigate to `Linker > Input > Additional Dependencies` and link the `Profiler.lib` & `Profiler-d.lib` file path.

Usage:
----------------------------
- `#include "Profile.h"`
- `Profiler::BeginSession("Profile");` to begin the profiler session.
- Place code like this in scopes you'd like to include in the profiling.
```
{
	Profiler::InstrumentationTimer timer(__FUNCSIG__);  // __FUNCSIG__ || "Profiled Scope Name"

	// Code
}
```
- `Profiler::EndSession();` to end the profiler session.
- `result.json` file will be exported into the &{ProjectDir} by default.
- JSON data can be viewed using https://ui.perfetto.dev/

Author & Contributor List
-------------------------
**Daniel Henshaw**
