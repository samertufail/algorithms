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
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*/

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}    
};

class Solution
{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        int len = intervals.size();
        if (newInterval.start > newInterval.end) return{};
        vector<Interval> res;
        int i = 0;
        for (; i < len; ++i)
        {
            if (newInterval.end < intervals[i].start) break; // No interval after this will overlap or match
            else if (newInterval.start > intervals[i].end) res.push_back(intervals[i]);
            else
            {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        res.push_back(newInterval);
        for (; i < len; ++i)
        {
            res.push_back(intervals[i]);
        }

        return res;
    }
};

void runTests()
{
    Solution s;
    vector<Interval> intervals = { Interval(1,2), Interval(3,5), Interval(6,7), Interval(8,10), Interval(12,16) };
    vector<Interval> res = s.insert(intervals, Interval(4,9));

    vector<Interval> intervals1 = { Interval(1,3), Interval(6,9) };
    vector<Interval> res1 = s.insert(intervals1, Interval(2,5));

}

int main(int argc, char *argv[]) {
    runTests();
}