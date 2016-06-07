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
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int len = s.length(); 
        string substr = "";
        int maxLen = 0;
        for (int i = 0; i < len; ++i)
        {
            size_t pos = substr.find(s[i]);
            if (pos != string::npos)
            {
                substr.erase(0, pos + 1);
            }
            substr += s[i];
            maxLen = max(maxLen, (int)substr.length());
        }
        return maxLen;
    }
};

void runTests()
{
    Solution s;
    assert(3 == s.lengthOfLongestSubstring("abcabcbb"));
    assert(1 == s.lengthOfLongestSubstring("bbbbb"));
    assert(3 == s.lengthOfLongestSubstring("pwwkew"));
}

int main(int argc, char *argv[]) {
    runTests();
}