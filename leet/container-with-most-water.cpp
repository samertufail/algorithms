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
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Sketch:
{ 3,2,1,4,3,2,6 };

6             x
5             |
4       x     |
3 x     | x   |
2 | x   | | x |
1 | | x | | | |
  0 1 2 3 4 5 6

*/

class Solution {
public:
    int maxAreaBrute(vector<int>& height) {
        int len = height.size();
        int area = 0, temparea = 0, maxarea = 0;

        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                temparea = (j - i) * min(height[i], height[j]);
                area = max(area, temparea);

                if (temparea > maxarea)
                {
                    maxarea = temparea;
                }
            }
        }

        return maxarea;
    }
    
    int maxAreaOptimized(vector<int>& height)
    {
        int i = 0, j = height.size() - 1, area = 0, maxarea = 0;
        while (i < j)
        {
            area = (j - i) * min(height[i], height[j]);
            maxarea = max(maxarea, area);
            (height[j] > height[i]) ? ++i : --j;
        }

        return maxarea;
    }
};

void runTests()
{
    Solution s;
    vector<int> heights = { 3,2,1,4,3,2,6 };

    assert(18 == s.maxAreaBrute(heights));
    assert(18 == s.maxAreaOptimized(heights));
}

int main(int argc, char *argv[]) {
    runTests();
}