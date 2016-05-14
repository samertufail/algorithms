#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <set>
#include <math.h>
#include <cassert>
using namespace std;

/* 
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		if (len < 1) return;

		int i = 0, j = 0;
		while (i < len)
		{
			if (nums[i] != 0)
			{
				swap(nums[j], nums[i]);
				++j;
			}

			++i;
		}
	}
};

void testEmpty()
{
	Solution s; vector<int> vec = {};
	s.moveZeroes(vec);
	assert(vec.size() == 0);
}
void testGiven()
{
	Solution s;
	vector<int> vecG = { 0, 1, 0, 3, 12 }; vector<int> vecE = { 1, 3, 12, 0, 0 };
	s.moveZeroes(vecG);
	assert(vecG == vecE);
}
int main(int argc, char *argv[]) {
	testEmpty();  testGiven();
}