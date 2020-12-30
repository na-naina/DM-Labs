#include <iostream>

#include <vector>
#include <thread>

#include "Timer.h"
#include "Graph.h"

int main()
{
	int n;
	std::cout << "Enter graph size" << std::endl;
	std::cin >> n;

	DMLab::Graph graph(n);
	graph.randInit(9);
	graph.print();

 	/*std::thread first([](DMLab::Graph graph) */{
 
 	//	Timer timer(Timer::CLog_Timer, "BruteForce");
 		auto [temp, sum] = graph.jUsTbRuTeFoRcE4HeAd(0);
 		std::cout << sum << std::endl;
 		for (int t : temp)
 		{
 			std::cout << t << " -> ";
 		}
		std::cout << std::endl;
  		}/*, graph);*/

	
	/*std::thread second([](DMLab::Graph graph)*/ {
		//Timer timer(Timer::CLog_Timer, "Greedy");
		auto [temp, sum] = graph.greedyTraverse(0);
		std::cout << sum << std::endl;
		for (int t : temp)
		{
			std::cout << t << " -> ";
		}
		}/*, graph);*/

	//first.join();
	//second.join();
}