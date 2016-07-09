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
Given an integer, write a function to determine if it is a power of two.

*/

/*
    8 = 1000
    7 = 0111 & = 0 - !0 = result

    6 = 0110
    5 = 0101 & = 0100 - !1 = result
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        return !(n & (n - 1));
    }
};

void runTests()
{
    Solution s;
    assert(true == s.isPowerOfTwo(8));
    assert(true == s.isPowerOfTwo(16));
    assert(false == s.isPowerOfTwo(-16));
    assert(false == s.isPowerOfTwo(0));
    assert(false == s.isPowerOfTwo(5));
}

int main(int argc, char *argv[]) {

    runTests();
}