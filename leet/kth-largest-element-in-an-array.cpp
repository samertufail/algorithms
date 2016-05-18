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
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 = k = array's length.
*/

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size(); if (len == 0) return 0;
		priority_queue<int, vector<int>> maxHeap;
		for (int i = 0; i < len; ++i) { maxHeap.push(nums[i]); }
		for (int i = 0; i < k - 1; ++i){ maxHeap.pop(); }
		return maxHeap.top();
	}
};

void test(vector<int>& vec, int k, int expected)
{
	Solution s;
	assert(s.findKthLargest(vec,k) == expected);
}

int main(int argc, char *argv[]) {
	test(vector<int>({ }), 5, 0);
	test(vector<int>({-1,-5,0,-2,-3}), 1, 0);
	test(vector<int>({-1,-1,-1,-1,-1}), 1, -1);
	test(vector<int>({3,2,1,5,6,4 }), 2, 5);
}