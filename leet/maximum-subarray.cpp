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
using namespace std;

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maxcur = nums[0], maxsum = nums[0];
        for (int i = 1; i < len; ++i)
        {
            maxcur = max(nums[i], nums[i] + maxcur);
            if (maxcur > maxsum) maxsum = maxcur;
        }

        return maxsum;
    }
};

void runTests()
{
    Solution s; 
    vector<int> nums1 = { -2,1,-3,4,-1,2,1,-5,4 };
    assert(6 == s.maxSubArray(nums1));

    vector<int> nums2 = { 1,2,3,4,5 };
    assert(15 == s.maxSubArray(nums2));

    vector<int> nums3 = { -2,-1 };
    assert(-1 == s.maxSubArray(nums3));
}

int main(int argc, char *argv[]) {
    runTests();
}