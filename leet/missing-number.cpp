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
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant extra space complexity?
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int insum = len * (len + 1) / 2;
        for (int i = 0; i < len; ++i)
        {
            sum += nums[i];
        }

        return insum - sum;
    }

    int missingNumber2(vector<int>& nums)
    {
        int len = nums.size();
        int res = len;
        for (int i = 0, count = 0; i < len; ++i, ++count)
        {
            res ^= count;
            res ^= nums[i];
        }
        return res;
    }

    int missingNumber3(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        sort(nums.begin(), nums.end());
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == mid) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
};

void runTestsM1()
{
    Solution s;
    vector<int> v1 = { 0, 1, 3 };
    assert(2 == s.missingNumber(v1));

    vector<int> v2 = { 0,1,2,4,5,6 };
    assert(3 == s.missingNumber(v2));

    vector<int> v3 = { 0,1,2,3,4,5,7 };
    assert(6 == s.missingNumber(v3));

    vector<int> v4 = { 1 };
    assert(0 == s.missingNumber(v4));
}

void runTestsM2()
{
    Solution s;
    vector<int> v1 = { 0, 1, 3 };
    assert(2 == s.missingNumber2(v1));

    vector<int> v2 = { 0,1,2,4,5,6 };
    assert(3 == s.missingNumber2(v2));

    vector<int> v3 = { 0,1,2,3,4,5,7 };
    assert(6 == s.missingNumber2(v3));

    vector<int> v4 = { 1 };
    assert(0 == s.missingNumber2(v4));
}

void runTestsM3()
{
    Solution s;
    vector<int> v1 = { 0, 1, 3 };
    assert(2 == s.missingNumber3(v1));

    vector<int> v2 = { 0,1,2,4,5,6 };
    assert(3 == s.missingNumber3(v2));

    vector<int> v3 = { 0,1,2,3,4,5,7 };
    assert(6 == s.missingNumber3(v3));

    vector<int> v4 = { 1 };
    assert(0 == s.missingNumber3(v4));
}


int main(int argc, char *argv[]) {
    runTestsM1(); runTestsM2(); runTestsM3();
}