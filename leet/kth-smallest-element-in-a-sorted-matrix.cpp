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
Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return -1;
        priority_queue < int, vector<int>, std::greater<int> > pq;

        for (auto r : matrix) for (auto c : r) pq.push(c);

        for (int i = 0; i < k - 1; ++i) pq.pop();

        return pq.top();
    }
};

void runTests()
{
    Solution s;
    vector<vector<int>> matrix = { {1, 5, 9}, {10, 11, 13}, {12, 13, 15} };
    assert(13 == s.kthSmallest(matrix, 8));
}

int main(int argc, char *argv[]) {

    runTests();
}