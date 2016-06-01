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
using namespace std;

/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

*/

class Solution {
public:
    void rotateNaive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ref; // O(n) space    
        for (int i = 0; i < k; ++i)
        {
            ref = nums;
            for (int j = 1, ind = 0; j <= n; ++j, ++ind)
            {
                // treat it like a circular buffer keep pushing one step forward
                nums[j % n] = ref[ind];
            }
        }
    }

    void rotateOptimized(vector<int>& nums, int k)
    {
        k = k % nums.size(); // nuteralize the bounds
        reverse(nums.begin(), nums.end()); // reverse all contents
        reverse(nums.begin(), nums.begin() + k); // reverse only the rotation numbers
        reverse(nums.begin() + k, nums.end()); // reverse the end numbers
    }
};

void runTests()
{
    Solution s;
    vector<int> v1 = { 1,2,3,4,5,6,7 };
    vector<int> expected = { 5,6,7,1,2,3,4 };
    s.rotateNaive(v1, 3);
    assert(expected == v1);

    vector<int> v2 = { 1,2,3,4,5,6,7 };
    s.rotateOptimized(v2, 3);
    assert(expected == v2);

    vector<int> v3 = { 1,2,3 };
    vector<int> expectedV3 = { 3,1,2 };
    s.rotateOptimized(v3, 7);
    assert(expectedV3 == v3);

    // Timing check in ms
    int clockstartNaive = clock();
    s.rotateNaive(v1, 10000);
    int clockstopNaive = clock();
    double naiveDuration = (clockstopNaive - clockstartNaive) / double(CLOCKS_PER_SEC) * 1000;

    clockstartNaive = clock();
    s.rotateOptimized(v1, 10000);
    clockstopNaive = clock();
    double optimizedDuration = (clockstopNaive - clockstartNaive) / double(CLOCKS_PER_SEC) * 1000;
    assert(optimizedDuration < naiveDuration);
}

int main(int argc, char *argv[]) {
    runTests();
}