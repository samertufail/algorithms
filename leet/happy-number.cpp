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
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer,
replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

*/


class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        unordered_set<int> cycle;
        while (n != 1)
        {
            int sum = 0;
            while (n)
            {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }

            if (cycle.find(sum) != cycle.end()) return false;
            else cycle.insert(sum);
            n = sum;
        }

        return true;
    }
};

void runTests()
{
    Solution s;
    assert(false == s.isHappy(2));
    assert(true == s.isHappy(19));
}
int main(int argc, char *argv[]) {

    runTests();
}