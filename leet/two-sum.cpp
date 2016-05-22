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
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(); if (len == 0) return{};
    	vector<int> res(2); unordered_map<int, int> map;
    	for (int i = 0; i < len; ++i)
    	{
    		if (map.find(target - nums[i]) == map.end())
    			map[nums[i]] = i;
    		else
    		{
    			res[0] = (map[target - nums[i]]);
    			res[1] = i;
    			return res;
    		}
    	}
    	return res;
    }
};