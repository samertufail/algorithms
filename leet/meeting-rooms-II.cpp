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
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

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
private:
    static bool cmp(const Interval& lhs, const Interval& rhs)
    {
        return lhs.start < rhs.start;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals)
    {
        int len = intervals.size();
        if (len <= 0) return 0;
        int rooms = 0;
        vector<bool> visited(len, false);

        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < len; ++i)
        {
            if (!visited[i])
            {
                ++rooms;
                int j = i + 1;
                Interval temp = intervals[i];
                while (j < len)
                {
                    if (!visited[j] && intervals[j].start >= temp.end)
                    {
                        temp = intervals[j];
                        visited[j] = true;
                    }
                    ++j;
                }
            }
        }

        return rooms;
    }
};

void runTests()
{
    Solution s;
    vector<Interval> intervals = { Interval(0,30), Interval(5,10), Interval(15,20) };
    assert(2 == s.minMeetingRooms(intervals));

    vector<Interval> intervals1 = { Interval(9,10), Interval(4,9), Interval(4,17) };
    assert(2 == s.minMeetingRooms(intervals1));

    vector<Interval> intervals2 = { Interval(1,5), Interval(8,9), Interval(8,9) };
    assert(2 == s.minMeetingRooms(intervals2));
}

int main(int argc, char *argv[]) {
    runTests();
}