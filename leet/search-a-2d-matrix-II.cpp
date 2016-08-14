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

Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = n - 1;
        while (l < m && r >= 0)
        {
            if (matrix[l][r] == target) return true;
            else if (matrix[l][r] > target) --r;
            else ++l;
        }
        
        return false;
    }
};

void runTests()
{
    Solution s;
    vector<vector<int>> matrix = {
        {1,   2,   3,  4, 5},
        {6,   7,   8,  9, 10},
        {11, 12,  13, 14, 15},
        {16, 17,  18, 19, 20},
        {21, 22,  23, 24, 25} };

    assert(true == s.searchMatrix(matrix, 19));
    assert(false == s.searchMatrix(matrix, 30));
}

int main(int argc, char *argv[]) {

    runTests();
}