#include <future>
#include <chrono>
#include <iostream>

#pragma once
struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> duration;
	std::string TimerName;
	unsigned int type;

	enum TimerType{
		SampleTimer = 0, CLog_Timer = 1
	};


	Timer(unsigned int type);
	Timer();
	Timer(std::string Name);
	Timer(unsigned int type, std::string Name);
	~Timer();
};

