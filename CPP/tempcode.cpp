#include <bits/stdc++.h>
using namespace std;
/*
You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i].
You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies.
Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.
*/

int maximumCandies(vector<int> &candies, int k)
{
	long long sum = 0;
	for (int candy : candies)
	{
		sum += candy;
	}

	// If total candies are less than number of children
	if (sum < k)
		return 0;

	int left = 1;
	int right = *max_element(candies.begin(), candies.end());

	while (left < right)
	{
		int mid = left + (right - left) / 2; // number of candies per child
		long long children = 0;				 // number of children that can get mid candies

		// Count how many children can get mid candies
		for (int pile : candies)
		{
			children += pile / mid;
		}

		if (children >= k)
		{
			left = mid + 1; // Try to give more candies per child
		}
		else
		{
			right = mid; // Need to give fewer candies per child
		}
	}
	return left;
}

int main()
{
	vector<int> candies = {5, 8, 6};
	int k = 3; // number of children
	cout << "Maximum candies each child can get: " << maximumCandies(candies, k) << endl;
	return 0;
}