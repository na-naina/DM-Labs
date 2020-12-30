#include "Graph.h"

#include "Combinatorics.h"

DMLab::Graph::Graph(int size)
	:size(size)
{
	adjMat = new std::pair<int, bool>* [size];
	for (int i = 0; i < size; i++)
		adjMat[i] = new std::pair<int, bool>[size];
}

DMLab::Graph::~Graph()
{
	for (int i = 0; i < size; i++)
		delete adjMat[i];
	delete adjMat;
}

void DMLab::Graph::randInit(int maxValue)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			adjMat[i][j].first = rand() % maxValue + 1;
			adjMat[i][j].second = false;
			if (i == j)
				adjMat[i][j].first = -1;
		}
}

void DMLab::Graph::print()
{
	std::cout << ' ';
	for (int i = 0; i < size; i++)
		std::cout << ' ' << i;
	std::cout << std::endl;

	for (int i = 0; i < size; i++) {
		std::cout << i << ' ';
		for (int j = 0; j < size; j++) {
			if (adjMat[i][j].first == -1)
			{
				std::cout << '-' << ' ';
				continue;
			}
			std::cout << adjMat[i][j].first << ' ';
		}
		std::cout << std::endl;
	}
}

std::pair<std::vector<int>, int> DMLab::Graph::greedyTraverse(int startVert)
{
	std::vector<int> seq;
	return greedyTraverse(startVert, seq, 0);
}

void DMLab::Graph::reset()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			adjMat[i][j].second = false;
}

std::pair<std::vector<int>, int> DMLab::Graph::greedyTraverse(int startVert, std::vector<int> seq, int currsum)
{
	for (int i = 0; i < size; i++) {
		adjMat[i][startVert].second = true;
	}
	seq.push_back(startVert);

	int min = INT_MAX;
	int nextVert;
	for(int j = 0; j < size; j++)
		if (adjMat[startVert][j].first < min && !adjMat[startVert][j].second) {
			nextVert = j;
			min = adjMat[startVert][j].first;
		}

	if (min == INT_MAX) {
		seq.push_back(seq[0]);
		currsum += adjMat[startVert][seq[0]].first;
		reset();
		return std::make_pair(seq, currsum);
	}
	else {
		currsum += adjMat[startVert][nextVert].first;
		return greedyTraverse(nextVert, seq, currsum);
	}
}


int DMLab::Graph::calculateSum(int* seq)
{
	int sum = 0;
	seq[size] = seq[0];
	for (int i = 0; i < size; i++)
		sum += adjMat[seq[i]][seq[i + 1]].first;
	return sum;
}

std::pair<std::vector<int>, int> DMLab::Graph::jUsTbRuTeFoRcE4HeAd(int startVert)
{
	int* seq = new int[size + 1];
	for (int i = 0; i < size; i++)
		seq[i] = i;

	int minsum = INT_MAX;
	std::vector<int> returnseq(size + 1, 0);
	do 
	{
		int t = calculateSum(seq);
		if (minsum > t) {
			minsum = t;
			for (int i = 0; i < size; i++)
				returnseq[i] = seq[i];
			returnseq[size] = seq[0];
		}
	} while (MyNext_Permutation(seq, seq + size));
	delete seq;
	return std::make_pair(returnseq, minsum);
}
