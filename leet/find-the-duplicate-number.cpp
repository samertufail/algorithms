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
#include <fstream>
#include <sstream>
#include <locale>
#include <map>
#include <iterator>
using namespace std;

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.


*/

class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;

        int slw = nums[0], fst = nums[nums[0]];
        while (slw != fst)
        {
            slw = nums[slw];
            fst = nums[nums[fst]];
        }

        fst = 0;
        while (slw != fst)
        {
            slw = nums[slw];
            fst = nums[fst];
        }

        return slw;
    }
};


void runTests()
{
    Solution s;
    vector<int> nums = { 3,1,3,4,2 };
    assert(3 == s.findDuplicate(nums));
}

int main(int argc, char *argv[]) {
    runTests();
}