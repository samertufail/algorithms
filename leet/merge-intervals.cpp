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
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

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
    static bool cmp(const Interval& lhs, const Interval& rhs)
    {
        return lhs.start < rhs.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        int len = intervals.size();
        if (len < 1) return { };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<bool> visited(len,false);
        vector<Interval> res;
        for (int i = 0; i < len; ++i)
        {
            if (!visited[i])
            {
                Interval temp = intervals[i]; int j = i + 1;
                while (j < len && temp.end >= intervals[j].start)
                {
                    temp.end = max(temp.end, intervals[j].end);
                    visited[j] = true;
                    ++j;
                }
                res.push_back(temp);
            }
        }

        return res;
    }
};

void runTests()
{
    Solution s;
    vector<Interval> intervals = { Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18) };
    vector<Interval> res = s.merge(intervals);

    vector<Interval> intervals1 = { Interval(1,4), Interval(2,3) };
    vector<Interval> res1 = s.merge(intervals1);

}

int main(int argc, char *argv[]) {
    runTests();
}