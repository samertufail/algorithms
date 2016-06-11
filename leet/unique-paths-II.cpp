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
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]

The total number of unique paths is 2.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); 

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int left = (j == 0) ? 0 : obstacleGrid[i][j - 1];
                int top = (i == 0) ? 0 : obstacleGrid[i - 1][j];
                if (i == 0 && j == 0 && obstacleGrid[i][j] == 0) obstacleGrid[i][j] = 1;
                else obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? 0 : top + left;
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};

void runTests()
{
    Solution s;
    vector<vector<int>> grid = { { 0,0,0 },
                                 { 0,1,0 },
                                 { 0,0,0 }
                               };

    assert(2 == s.uniquePathsWithObstacles(grid));

    vector<vector<int>> grid2{ {1,0} };
    assert(0 == s.uniquePathsWithObstacles(grid2));

    vector<vector<int>> grid3{ { 0 } };
    assert(1 == s.uniquePathsWithObstacles(grid3));
}

int main(int argc, char *argv[]) {
    runTests();
}