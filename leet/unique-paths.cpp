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
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

class Solution {
public:
    int uniqueHelper(int row, int col, vector<vector<int>>& grid, unordered_set<int>& visited, int weight)
    {
        if (row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0) return 0; 
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
        {
            if (visited.find(weight) != visited.end()) return 0;
            else
            {
                visited.emplace(weight);
                return 1;
            }
        }
        else
        {
            return uniqueHelper(row + 1, col, grid, visited, weight + grid[row][col]) + 
                   uniqueHelper(row, col + 1, grid, visited, weight + grid[row][col]);
        }
    }

    // Recursive solution using DFS, suboptimal compared to DP solution
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        unordered_set<int> visited;
        for (int i = 0, weight = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j, ++weight)
            {
                grid[i][j] = weight;
            }
        }

        return uniqueHelper(0, 0, grid, visited,0);
    }

    // Solution using dynamic programming
    int uniquePathsDP(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m-1][n-1];
    }
};

void runTests()
{
    Solution s;
    assert(3 == s.uniquePaths(2, 5));
    assert(3 == s.uniquePathsDP(2, 3));
}

int main(int argc, char *argv[]) {
    runTests(); getchar();
}