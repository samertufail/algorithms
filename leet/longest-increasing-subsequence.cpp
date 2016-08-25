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
#include <numeric> 
#include <thread>
#include <memory>
#include <mutex>
#include <iomanip>
using namespace std;

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], 
therefore the length is 4. Note that there may be more than one LIS combination, 
it is only necessary for you to return the length.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

void runTests()
{
    Solution s;
	
    vector<int> arr = { 10, 9, 2, 5, 3, 7, 101, 18 };
    assert(4 == s.lengthOfLIS(arr));
}

int main(int argc, char *argv[]) {

    runTests();
}