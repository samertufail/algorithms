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
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k <= 0) return{};

        unordered_map<int, int> freq;
        for (int val : nums)
        {
            if (freq.find(val) != freq.end()) ++freq[val];
            else freq[val] = 1;
        }

        multimap<int, int> multmap;
        for (auto fval : freq)
        {
            multmap.insert(pair<int,int>(fval.second, fval.first));
        }

        vector<int> res;
        auto iter = multmap.rbegin();
        for (int i = 0; i < k; ++i, ++iter)
        {
            res.push_back(iter->second);
        }

        return res;
    }
};

void runTests()
{
    Solution s;
    vector<int> v1 = { 1,1,1,2,2,3 };
    vector<int> e1 = { 1,2 };
    assert(e1 == s.topKFrequent(v1, 2));
}

int main(int argc, char *argv[]) {

    runTests();
}