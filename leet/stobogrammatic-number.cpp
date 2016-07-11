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
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.length();
        if (len == 0) return true;
        if (num.find_first_of("23457") != string::npos) return false;

        unordered_map<char, char> map = { {'0','0'}, {'1','1'}, {'6','9'}, {'8', '8'}, {'9','6'} };
        int l = 0, r = len - 1;
        while (l <= r)
        {
            if (map[num[l]] != num[r]) return false;
            ++l; --r;
        }
        return true;
    }
};

void runTests()
{
    Solution s;
    assert(true == s.isStrobogrammatic("6969"));
    assert(false == s.isStrobogrammatic("23"));
    assert(true == s.isStrobogrammatic(""));
}

int main(int argc, char *argv[]) {

    runTests();
}