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
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        size_t len = str.size();
        int maxSubStrLen = len / 2, i = 1;
        while (i <= maxSubStrLen)
        {
            string sub = str.substr(0, i);
            int j = i;
            bool match = false;
            while (j < len)
            {
                if (sub != str.substr(j, i)) { break; }
                j += i;
            }
            if (j == len)  return true; else ++i;
        }

        return false;
    }
};

void runTests()
{
    Solution s;
    assert(s.repeatedSubstringPattern("abaababaab") == true);
    assert(s.repeatedSubstringPattern("abab") == true);
    assert(s.repeatedSubstringPattern("aba") == false);
    assert(s.repeatedSubstringPattern("abcabcabcabc") == true);
    assert(s.repeatedSubstringPattern("ababab") == true);
}

int main(int argc, char *argv[]) {

    runTests();
}