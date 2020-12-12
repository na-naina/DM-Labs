#include "Timer.h"

Timer::Timer(unsigned int type)
	:duration(0.0f), TimerName(""), type(type)
{
	start = std::chrono::high_resolution_clock::now();
}

Timer::Timer()
	:duration(0.0f), TimerName(""), type(0)
{
	start = std::chrono::high_resolution_clock::now();
}

Timer::Timer(std::string Name)
	: duration(0.0f), TimerName(Name), type(0)
{
	start = std::chrono::high_resolution_clock::now();
}

Timer::Timer(unsigned int type, std::string Name)
	: duration(0.0f), TimerName(Name), type(type)
{
	start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;

	if(type == CLog_Timer)
	std::cout << std::fixed << std::endl << ((TimerName != "") ? "[" + TimerName + "]: " : "") << duration.count() << "s" << std::endl;
}
