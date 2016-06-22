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
using namespace std;

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

class Solution {
public:

    int GetMax(vector<int>& height, int start, int end)
    {
        int index = start;
        for (int i = start + 1; i <= end; ++i)
        {
            if (height[i] > height[index])
                index = i;
        }
        return index;
    }

    int CalcVolume(vector<int>& height, int start, int end)
    {
        if (start >= end) return 0;
        int vol = 0, minvol = min(height[start], height[end]);
        for (int i = start + 1; i < end; ++i)
        {
            vol += minvol - height[i];
        }
        return vol;
    }

    int GetVolume(vector<int>& height, int start, int end, bool left)
    {
        if (start >= end) return 0;
        int vol = 0;
        if (left)
        {
            int idx = GetMax(height, start, end - 1);
            vol += CalcVolume(height, idx, end);
            vol += GetVolume(height, start, idx, left);
        }
        else
        {
            int idx = GetMax(height, start + 1, end);
            vol += CalcVolume(height, start, idx);
            vol += GetVolume(height, idx, end, left);
        }
        return vol;
    }

    int trap(vector<int>& height) {
        int len = height.size();
        if (len < 1) return 0;

        int index = GetMax(height, 0, len - 1);
        int volLeft = GetVolume(height, 0, index, true);
        int volRight = GetVolume(height, index, len - 1, false);
        return volLeft + volRight;
    }

    int trapOptimised(vector<int>& height)
    {
        int len = height.size();
        if (len <= 1) return 0;

        int maxl = 0, maxr = 0, leftb = 0, rightb = len - 1, water = 0;
        while (leftb <= rightb)
        {
            if (height[leftb] <= height[rightb])
            {
                if (height[leftb] >= maxl) maxl = height[leftb];
                else water += maxl - height[leftb];
                ++leftb;
            }
            else
            {
                if (height[rightb] >= maxr) maxr = height[rightb];
                else water += maxr - height[rightb];
                --rightb;
            }
        }

        return water;
    }
};


void runTests()
{
    Solution s;
    vector<int> elevation = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    assert(6 == s.trap(elevation));
    assert(6 == s.trapOptimised(elevation));

    vector<int> elevation1 = { 0,2,0 };
    assert(0 == s.trap(elevation1));
    assert(0 == s.trapOptimised(elevation1));

    vector<int> elevation2 = { 2,0,2 };
    assert(2 == s.trap(elevation2));
    assert(2 == s.trapOptimised(elevation2));

    vector<int> elevation3 = { 4,2,3 };
    assert(1 == s.trap(elevation3));
    assert(1 == s.trapOptimised(elevation3));
}

int main(int argc, char *argv[]) {
    runTests();
}