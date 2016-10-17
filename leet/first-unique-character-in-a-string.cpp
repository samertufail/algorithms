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
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        if (len == 0) return -1;

        unordered_map<char, int> freq(len);
        for (char& c : s) ++freq[c];

        for (int i = 0; i < len; ++i) if (freq[s[i]] == 1) return i;
        
        return -1;
    }
};

void runTests()
{
    Solution s;
    assert(0 == s.firstUniqChar("leetcode"));
    assert(2 == s.firstUniqChar("loveleetcode"));
}

int main(int argc, char *argv[]) {

    runTests(); getchar();
}