#pragma once


#include <stdlib.h> 
#include <tuple>
#include <vector>
#include <iostream>

namespace DMLab {

	class Graph
	{
	private:
		int size;
		std::pair<int, bool>** adjMat;

		std::pair<std::vector<int>, int> greedyTraverse(int startVert, std::vector<int> seq, int currsum);
		void reset();
		int calculateSum(int* seq);

	public:
		Graph(int size);
		~Graph();

		void randInit(int maxValue);
		void print();


		std::pair<std::vector<int>, int> greedyTraverse(int startVert);
		std::pair<std::vector<int>, int> jUsTbRuTeFoRcE4HeAd(int startVert);

	};

}

