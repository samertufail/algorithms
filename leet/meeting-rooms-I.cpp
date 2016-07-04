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
determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.

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
    bool canAttendMeetings(vector<Interval>& intervals) {
    {
        int len = intervals.size();
        if (len <= 0) return true;
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < len - 1; ++i)
        {
            if (intervals[i].end > intervals[i + 1].start) return false;
        }

        return true;
    }
};

void runTests()
{
    Solution s;
}

int main(int argc, char *argv[]) {
    runTests();
}