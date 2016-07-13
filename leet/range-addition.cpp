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
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.
*/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = updates.size();
        if (length == 0 && n == 0) return{};
        vector<int> res(length, 0);

        for (int i = 0; i < n; ++i)
        {
            auto begin = res.begin() + updates[i][0];
            auto end = res.begin() + updates[i][1] + 1;
            for (; begin != end; ++begin) *begin += updates[i][2];
        }

        return res;
    }
};
void runTests()
{
    Solution s;
    vector<vector<int>> updates = { {1,  3,  2}, {2,  4,  3}, {0,  2, -2} };
    vector<int> res = { -2,0,3,5,3 };
    assert(res == s.getModifiedArray(5, updates));
}

int main(int argc, char *argv[]) {

    runTests();
}