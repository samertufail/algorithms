#include "stdafx.h"
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
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].   */

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int len = nums.size(); if (len == 0) return{};
		vector<string> res({ to_string(nums[0]) }); int i = 1, k = 0 , cnt = 0;
		while (i < len)
		{
			while (i < len && nums[i] - nums[i - 1] == 1) { ++cnt; ++i; }
			if(cnt > 0)
			{
				res[k] += "->" + to_string(nums[i - 1]);
				if(i < len) res.push_back(to_string(nums[i]));
				++k; cnt = 0;
			}
			else { res.push_back(to_string(nums[i])); ++k; } ++i;
			
		}
		return res;
	}
};

void testEmptyRange() {
	Solution s;
	vector<int> nums = { };
	vector<string> expected = { };
	assert(s.summaryRanges(nums) == expected);
}
void testSingleRange() {
	Solution s;
	vector<int> nums = {0,1};
	vector<string> expected = {"0->1"};
	assert(s.summaryRanges(nums) == expected);
}
void testDecoupledRange() {
	Solution s;
	vector<int> nums = { 0,5,7 };
	vector<string> expected = { "0","5","7" };
	assert(s.summaryRanges(nums) == expected);
}
void testMediumRange() {
	Solution s;
	vector<int> nums = { 0,1,2,4,5,7 };
	vector<string> expected{ "0->2","4->5","7" };
	assert(s.summaryRanges(nums) == expected);
}
void testLongRange() {
	Solution s;
	vector<int> nums = { 0,1,2,4,5,7,9,10,12,14,15,16,27,28 };
	vector<string> expected = { "0->2","4->5","7","9->10","12","14->16","27->28" };
	assert(s.summaryRanges(nums) == expected);
}

int main(int argc, char *argv[]) {
	Solution s;
	testEmptyRange();
	testSingleRange();
	testDecoupledRange();
	testMediumRange();
	testLongRange();
}