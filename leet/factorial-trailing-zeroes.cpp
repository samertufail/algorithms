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
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/

class Solution {
public:
    int trailingZeroesBrute(int n) {
        if (n < 5) return 0;

        int count = 0;
        while (n > 4 )
        {
            n = n - 5;
            ++count;
        }

        return n == 0 ? count + 1 : count;
    }

    int trailingZeroesOptimal(int n) {
        if (n < 5) return 0;

        int count = 0;
        while (n > 4)
        {
            n = n / 5;
            count += n;
        }

        return n == 0 ? count + 1 : count;
    }
};

void runTests()
{
    Solution s;
    assert(2 == s.trailingZeroesBrute(11));
    assert(3 == s.trailingZeroesBrute(16));
    assert(6 == s.trailingZeroesBrute(25));
    assert(4 == s.trailingZeroesBrute(23));


    assert(2 == s.trailingZeroesOptimal(11));
    assert(3 == s.trailingZeroesOptimal(16));
    assert(6 == s.trailingZeroesOptimal(25));
    assert(4 == s.trailingZeroesOptimal(23));
}

int main(int argc, char *argv[]) {
    runTests();
}