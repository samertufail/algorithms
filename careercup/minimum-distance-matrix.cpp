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

Given a matrix of -1's and 0's, display a matrix which contains minimum distance to reach nearest 0 for that particular position.

Example:

Input: 
 -1  0 -1
 -1 -1 -1
 -1 -1 -1

Output:
 1 0 1
 2 1 2
 3 2 3

*/

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& matrix, int distance)
    {
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size()) return;
        if(distance <= matrix[r][c] || matrix[r][c] == -1)
        {
            matrix[r][c] = distance;
            dfs(r + 1, c, matrix, distance + 1);
            dfs(r - 1, c, matrix, distance + 1);
            dfs(r, c + 1, matrix, distance + 1);
            dfs(r, c - 1, matrix, distance + 1);
        }
    }
public:
    vector<vector<int>> minDistances(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return{};
        
        int rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    dfs(i, j, matrix, 0);
                }
            }
        }

        return matrix;
    }
};

void runTests()
{
    Solution s;
    vector<vector<int>> matrix = { {-1,0,-1}, {-1,-1,-1 }, {-1,-1,-1} };
    vector<vector<int>> expected = { {1,0,1}, {2,1,2}, {3,2,3} };
    assert(s.minDistances(matrix) == expected);
}

int main(int argc, char *argv[]) {

    runTests();
}