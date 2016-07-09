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
using namespace std;

/*
Given an integer, write a function to determine if it is a power of three.
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};

void runTests()
{
    Solution s;
    assert(true == s.isPowerOfThree(9));
    assert(true == s.isPowerOfThree(27));
    assert(false == s.isPowerOfThree(-9));
    assert(false == s.isPowerOfThree(0));
    assert(true == s.isPowerOfThree(1));
}

int main(int argc, char *argv[]) {
    runTests();
}