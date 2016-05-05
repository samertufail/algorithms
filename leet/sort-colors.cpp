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

/*  Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent,
    with the colors in the order red, white and blue.
	
	Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
	Note: You are not suppose to use the library's sort function for this problem.  */

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() < 1) return;
		int i = 0, j = 0, n = nums.size() - 1;

		// space out the array first half is color start = red | mid = white | end = blue
		// track using two pointers increment for start decrement for mid will have white
		while (j <= n)
		{
			if (nums[j] == 0) { swap(nums[j], nums[i]); ++j; ++i; }
			else if (nums[j] == 2) { swap(nums[j], nums[n]); --n; }
			else ++j;
		}
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> colors = { 1,0,2,1,1,1,0,0,0,0 }, cloneSort = colors, cloneUnsorted = colors;
	s.sortColors(colors); 
	sort(cloneSort.begin(), cloneSort.end());
	assert(equal(colors.begin(), colors.end(), cloneSort.begin(), cloneSort.end())         == true);
	assert(equal(colors.begin(), colors.end(), cloneUnsorted.begin(), cloneUnsorted.end()) == false);
}