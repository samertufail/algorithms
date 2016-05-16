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
#include <ctime>
using namespace std;

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
It doesn't matter what you leave beyond the new length. .
*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size(); if (len < 2) return len;
		int count = 0;
		for (int i = 2; i < len; ++i)
		{
			if (nums[i] == nums[i - count - 2]) ++count;
			else nums[i - count] = nums[i];
		}
		return len - count;
	}
};

void testEmpty()
{
	Solution s; vector<int> vec = {};
	assert(s.removeDuplicates(vec) == 0);
}
void testAllDuplicates()
{
	Solution s; vector<int> vec = { 1,1,1,1,1,1,1,1 };
	assert(s.removeDuplicates(vec) == 2);
}
void testUniformDistribution()
{
	Solution s; vector<int> vec = { 1,1,2,2,3,3,4,4,4,5,5,5,5 };
	assert(s.removeDuplicates(vec) == 10);
}

int main(int argc, char *argv[]) {
	testEmpty(); testAllDuplicates(); testUniformDistribution();
}