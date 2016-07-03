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
using namespace std;

/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3


*/

class MovingAverage {
private:
    vector<int> average;
    int curp;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : curp(0), size(size) {

    }

    double next(int val) {
        if (average.size() == size)
        {
            curp = curp == size ? 0 : curp;
            average[curp % size] = val; ++curp;
            return (accumulate(average.begin(), average.end(), 0.0)) / size;
        }
        else
        {
            average.push_back(val);
            return (accumulate(average.begin(), average.end(), 0.0)) / (double)average.size();
        }
    }
};

/**
* Your MovingAverage object will be instantiated and called as such:
* MovingAverage obj = new MovingAverage(size);
* double param_1 = obj.next(val);
*/

void runTests()
{
    MovingAverage m(3);
    assert(1 == m.next(1));
    assert(5.5 == m.next(10));
    assert(4.6 == m.next(3));
    assert(6 == m.next(5));
}

int main(int argc, char *argv[]) {
    runTests();
}