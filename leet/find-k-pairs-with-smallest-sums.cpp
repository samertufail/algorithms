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
using namespace std;

/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
*/

class Compare
{
public:
    bool operator()(pair<int, int>& lhs, pair<int, int>& rhs)
    {
        return lhs.first + lhs.second > rhs.first + rhs.second;
    }
};
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        priority_queue <pair<int, int>, vector<pair<int, int>>, Compare > pq;

        for (int i = 0; i < n1; ++i)
        {
            for (int j = 0; j < n2; ++j)
            {
                pq.push(make_pair(nums1[i], nums2[j]));
            }
        }

        vector<pair<int, int>> res;
        for (int i = 0; i < k && !pq.empty(); ++i)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
void runTests()
{
    Solution s;
    vector<int> nums1 = { 1, 1, 2 }, nums2 = { 1, 2, 3 };
    vector < pair<int, int>> res = { {1,1}, {1,1} };
    assert(res == s.kSmallestPairs(nums1, nums2, 2));

    vector<int> nums1x = { 1,7,11 }, nums2x = { 2,4,6 };
    vector < pair<int, int>> resx = { { 1,2 },{ 1,4 }, {1,6} };
    assert(resx == s.kSmallestPairs(nums1x, nums2x, 3));

    vector<int> nums1y = { 1,2 }, nums2y = { 3 };
    vector < pair<int, int>> resy = { { 1,3 },{ 2,3 } };
    assert(resy == s.kSmallestPairs(nums1y, nums2y, 3));
}

int main(int argc, char *argv[]) {

    runTests();
}