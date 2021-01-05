#include <iostream>
#include "Timer.h"
#include "algorithms.h"


int main()
{
	int values[] = { 5, 15, 30, 50 };
	int n;
	for (int i = 0; i < 4; i++)
	{
		n = values[i];
	std::cout << "For n = " << n << " fib(n) = " << fib_formula(n);
	{
		Timer timer(Timer::CLog_Timer, "iterative");
		fib_iterative(n);
	}
	{
		Timer timer(Timer::CLog_Timer, "recursive");
		fib_recursive(n);
	}
	{
		Timer timer(Timer::CLog_Timer, "formula");
		fib_formula(n);
	}
	std::cout << std::endl;
		std::cout << "Hanoi solution for n = " << n << ":" << std::endl;
		{
			Timer timer(Timer::CLog_Timer, "hanoi");
			std::string* temp = new std::string(hanoi(n));
			std::cout << *temp;
			delete temp;
		}

	std::cout << "-----------------------" << std::endl;
	std::cin.get();
	}
}