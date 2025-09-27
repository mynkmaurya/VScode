#include <bits/stdc++.h>
using namespace std;
vector<int> sortArray(vector<int> &nums)
{
	 int n = nums.size();
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++) 
		{
		 if(nums[i] > nums[j]) 
		 {
		 	swap(nums[i], nums[j]);
		 }
		 else
		 {
		 	continue;
		 }
		}
		
	}
 return nums;
	
}

int main()
{
	vector<int> nums = {10, 0, 9, 7, 2};
	int hey = sortArray(nums);
	cout << hey;
	return 0;
}
