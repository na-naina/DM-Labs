#include "Timer.h"
#include <thread>
#include "Combinatorics.h" 
#include <fstream>

#define MaxSizeValue 10


//threaded code for better visualization of time difference 

int main() 
{   
// 	//combinations
// {
// 	std::thread first([]() {
// 
// 		int x[MaxSizeValue];
// 
// 		for (int i = 0; i < MaxSizeValue; i++) {
// 			x[i] = i + 1;
// 		}
// 
// 		Timer timer(Timer::CLog_Timer, "BWO_COMB");
// 		BWO_COMB<int>(x, x + MaxSizeValue, MaxSizeValue/2,
// 			[](int* begin, int* end, const long long& combo) {
// 
// 				//do something with combination here(e.g. print it)...
// 
// 			});
// 		});
// 
// 
// 	std::thread second([]() {
// 
// 		int x[MaxSizeValue];
// 
// 		for (int i = 0; i < MaxSizeValue; i++) {
// 			x[i] = i + 1;
// 		}
// 
// 		Timer timer(Timer::CLog_Timer, "BM_COMB");
// 		BM_COMB<int>(x, x + MaxSizeValue, MaxSizeValue/2,
// 			[](int* combBegin, int* combEnd) {
// 				
// 				//do something with combination here(e.g. print it)...
// 
// 			});
// 
// 		});
// 
// 
// 	second.join();
// 	first.join();
// }
// 
// std::cout << "------------------";
// 
// //permutations
// {
// 	std::thread first([]() {
// 		int x[MaxSizeValue];
// 
// 		for (int i = 0; i < MaxSizeValue; i++) {
// 			x[i] = i + 1;
// 		}
// 		Timer timer(Timer::CLog_Timer, "STD_NP");
// 		do {
// 
// 			//do something with permutation here(e.g. print it)...
// 
// 		} while (std::next_permutation(x, x + MaxSizeValue));
// 
// 		});
// 
// 	std::thread second([]() {
// 
// 		int x[MaxSizeValue];
// 
// 		for (int i = 0; i < MaxSizeValue; i++) {
// 			x[i] = i + 1;
// 		}
// 
// 		Timer timer(Timer::CLog_Timer, "MY_NP");
// 		do {
// 
// 			//do something with permutation here(e.g. print it)...
// 
// 		} while (MyNext_Permutation(x, x + MaxSizeValue));
// 
// 
// 		});
// 
// 	std::thread third([]() {
// 		int x[MaxSizeValue];
// 
// 		for (int i = 0; i < MaxSizeValue; i++) {
// 			x[i] = i + 1;
// 		}
// 		Timer timer(Timer::CLog_Timer, "HEAP_ALGO");
// 		heapAlgo<int>(x, x + MaxSizeValue, MaxSizeValue, [](int* permB, int* permE)
// 			{
// 				//do something with permutation here(e.g. print it)...
// 			});
// 		});
// 
// 	first.join();
// 	second.join();
// 	third.join();
// }
	int x[10];
	for (int i = 0; i < 10; i++) {
		x[i] = i + 1;
	}
	BM_COMB<int>(x, x + 6, 3, [](int* combB, int* combE) {
		int N = combE - combB;
		heapAlgo<int>(combB, combE, N, [](int* permB, int* permE) {
			for (int i = 0; i < permE - permB; i++)
				std::cout << permB[i] << ' ';
			std::cout << std::endl;
			});
		
		});
}