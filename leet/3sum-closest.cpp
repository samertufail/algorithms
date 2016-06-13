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
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.

Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        int len = nums.size();
        if (len < 3) return 0;

        int i = 0, res = nums[0] + nums[1] + nums[2];
        int sum = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i)
        {
            int j = i + 1;
            int k = len - 1;

            while (j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (target == sum) return sum;
                if (abs(target - sum) < abs(target - res))
                {
                    res = sum;
                }
                if (sum < target) ++j;
                else --k;
            }
        }

        return res;
    }
};

void runTests()
{
    Solution s;
    assert(3 == s.threeSumClosest(vector<int>{0,1,2}, 3));
    assert(2 == s.threeSumClosest(vector<int>{-1, 2, 1, -4}, 1));
    assert(6 == s.threeSumClosest(vector<int>{-2,3,4,1,-1}, 6));
}

int main(int argc, char *argv[]) {
    runTests();
}