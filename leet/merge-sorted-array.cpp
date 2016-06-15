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
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
        int end = m + n - 1;
        for (int i = m - 1, j = n - 1; end >= 0; --end)
        {
            if (j < 0) nums1[end] = nums1[i--];
            else if (i < 0) nums1[end] = nums2[j--];
            else if (j >= 0 && nums2[j] > nums1[i]) nums1[end] = nums2[j--];
            else nums1[end] = nums1[i--];
        }
    }
};

void runTests()
{
    Solution s;
    vector<int> nums1(8, 0);
    vector<int> nums2(4, 0);
    vector<int> expected;
    // vec 1 = 1 2 3 4  vec 2 = 3 4 5 6  final: 1 2 3 3 4 4 5 6
    for (int i = 0; i < 4; ++i) { nums1[i] = i + 1; expected.push_back(i + 1);  }
    for (int i = 0; i < 4; ++i) { nums2[i] = i + 3; expected.push_back(i + 3); }

    sort(expected.begin(), expected.end());
    s.merge(nums1, 4, nums2, 4);

    assert(nums1 == expected);
  
}

int main(int argc, char *argv[]) {
    runTests();
}