#pragma once
#include <algorithm>
#include <iostream>
#include <bitset>

//
//Permutations
//

template <class type>
bool MyNext_Permutation(type* begin, type* end, bool(*comp)(const type& a, const type& b)) {

	if (begin == end)
		return false;
	type* i = begin;
	++i;
	if (i == end)
		return false;
	i = end;
	--i;

	while(1)
	{
		type* ii = i;
		--i;
		if (comp(*i, *ii))
		{
			type* j = end;
			while (!comp(*i, *--j))
			{
			}
			std::iter_swap(i, j);
			std::reverse(ii, end);
			return true;
		}
		if (i == begin)
		{
			std::reverse(begin, end);
			return false;
		}
	}
}


template <class type>
bool MyNext_Permutation(type* begin, type* end) {
	return MyNext_Permutation<type>(begin, end, [](const type& a, const type& b) {return a < b; });
}



template<class type>
void swap(type& a, type& b)
{
	type t = a;
	a = b;
	b = t;
}

template <class type>
void heapAlgo(type* begin, type* end, int& size, void(*permutefunc)(type* permuteBegin, type* permuteEnd))
{
	int N = end - begin;
	if (N == 1) {
		permutefunc(begin, begin + size);
		return;
	}

	for (int i = 0; i < N; i++) {
		heapAlgo(begin, end - 1, size, permutefunc);

		if (N % 2 == 1)
			swap(begin[0], begin[(N) - 1]);
		else
			swap(begin[i], begin[(N) - 1]);
	}
}

template <class type>
void heapAlgo(type* begin, type* end, int& size)
{
	heapAlgo<type>(begin, end, size, [](type* permB, type* permEnd) {});
}

//
//Combinations
//

template<class type>
void BM_COMB(type* begin, type* end, int K, void(*combofunc)(type* combBegin, type* combEnd))
{
	int N = end - begin;
	bool* bitmask = (bool*)_malloca(N * sizeof(bool));
	if (bitmask) {

		for (int i = 0; i < N-K; i++)
			bitmask[i] = 0;

		for (int i = N-K; i < N; i++)
			bitmask[i] = 1;
		
		
		type* intermedComb = (type*)_malloca(K * sizeof(type));
		if (intermedComb) { do {

			int t = 0;
			for (int i = 0; i < N; i++) {
				if (bitmask[i] == 1)
				{
					intermedComb[t] = *(begin + i);
					t++;
				}
			}
			combofunc(intermedComb, intermedComb + K);		

		} while (MyNext_Permutation(bitmask, bitmask + N)); //for nice combo iteration order better to use prev permute function, but i was too lazy to implement a whole other function,
															//so in the worst case scenario where order is crucial, just use std::prev_permutation
	}}
}

template<class type>
void BM_COMB(type* begin, type* end, int K) {
	BM_COMB<type>(begin, end, K, [](type* cbegin, type* cend) {});
}



template<class type>
void BWO_COMB(type* begin, type* end, int k, void(*combofunc)(type* begin, type* end, const long long& combomask))
{
	int n = end - begin;
	long long combo = (1i64 << k) - 1;
	while (combo < 1i64 << n) {

		combofunc(begin, end, combo);
		long long x = combo & -combo; //gets a 
		long long y = combo + x;
		long long z = (combo & ~y);
		combo = z / x;
		combo >>= 1i64;
		combo |= y;
	}
}

template<class type>
void BWO_COMB(type* begin, type* end, int k)
{
	BWO_COMB<type>(begin, end, k, [](type* begin, type* end, const long long& combo) {});
}