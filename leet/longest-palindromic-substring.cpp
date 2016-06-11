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
Given a string S, find the longest palindromic substring in S. 

You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();

        string longestSubString = "";
        int maxLen = 0;
        string temp = "";
        for (int i = 0, count = 1; i < len; ++i, ++count)
        {
            for (int j = 0; j < len; ++j)
            {
                temp = s.substr(j, count);
                if (isPalindrome(temp))
                {
                    if (temp.size() > maxLen)
                    {
                        maxLen = temp.size();
                        longestSubString = temp;
                    }
                }
            }
        }
        return longestSubString;
    }


    bool isPalindrome(string& substr)
    {
        string tempstr = substr;
        reverse(tempstr.begin(), tempstr.end());
        return tempstr == substr;
    }

    string longestPalindromeOp1(string s) {
        int len = s.length();

        string longestSubString = "";
        int maxLen = 0;
        string temp = "";
        for (int i = 0, j = 0, k = 0; i < len; ++i)
        {
            j = i, k = i;
        
            // Even/Odd by skipping characters
            while (k < len - 1 && s[k + 1] == s[k]) ++k;

            // Expand using a pivot
            while (k < len - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; }
            
            temp = s.substr(j, k - j + 1);
            if (temp.size() > maxLen)
            {
                maxLen = temp.size();
                longestSubString = temp;
            }

        }
        return longestSubString;
    }
};

void runTests()
{
    Solution s;
    assert("abbba" == s.longestPalindrome("adcarrabbba"));
    assert("abbba" == s.longestPalindrome("bbcarraabbba"));
    assert("bbbbb" == s.longestPalindrome("bbbbb"));

    assert("rrarr" == s.longestPalindromeOp1("arrarr"));
    assert("abbba" == s.longestPalindromeOp1("adcarrabbba"));
    assert("abbba" == s.longestPalindromeOp1("bbcarraabbba"));
    assert("bbbbb" == s.longestPalindromeOp1("bbbbb"));
}

int main(int argc, char *argv[]) {
    runTests();
}