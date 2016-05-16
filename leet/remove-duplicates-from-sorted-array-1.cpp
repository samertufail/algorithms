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
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size(); if (len < 2) return len;
		int count = 0;
		for (int i = 1; i < len; ++i)
		{
			if (nums[i] == nums[i - count - 1]) ++count;
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
	assert(s.removeDuplicates(vec) == 1);
}
void testUniformDistribution()
{
	Solution s; vector<int> vec = { 1,1,2,2,3,3,4,4,4,5,5,5,5 };
	assert(s.removeDuplicates(vec) == 5);
}

int main(int argc, char *argv[]) {
	testEmpty(); testAllDuplicates(); testUniformDistribution();
}

