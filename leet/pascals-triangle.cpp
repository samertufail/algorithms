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
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

    [
            [1],
           [1,1],
          [1,2,1],
         [1,3,3,1],
        [1,4,6,4,1]
    ]

*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) return {};
        if (numRows == 1) return{ { 1 } };
        vector<vector<int>> res;
        res.push_back({ 1 });

        for (int i = 1; i < numRows; ++i)
        {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < i; ++j) temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            temp.push_back(1);
            res.push_back(temp);
        }

        return res;
    }
};

void runTests()
{
    Solution s;
    vector<vector<int>> exp1 = { {1}, {1,}, {1,2,1}, {1,3,3,1}, {1,4,6,4,1} };
    assert(exp1 == s.generate(5));
}
int main(int argc, char *argv[]) {

    runTests();
}