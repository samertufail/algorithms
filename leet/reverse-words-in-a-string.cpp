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
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

*/

class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        if (len <= 0) return;
        int start = s.find_first_not_of(" ");
        int end = s.find_last_not_of(" ");
        
        if (start == string::npos) { s = ""; return; }

        // Nuetralise the string from both end taking care of leading and trailing spaces
        s = s.substr(start, end - start + 1);
        reverse(s.begin(), s.end());
        len = s.length();

        int i = 0, pos = 0;
        while (i < s.length())
        {
            pos = s.find(" ", i);
            if (pos != string::npos)
            {
                reverse(s.begin() + i, s.begin() + pos);
                i = pos + 1;

                // From first space onwards remove all other spaces
                while (s[i] == ' ') { s.erase(i, 1); }
            }
            else ++i;
        }

        // Reverse the end of the string
        pos = s.find_last_of(" ");
        reverse(s.begin() + pos + 1, s.end());
    }
};

void runTests()
{
    Solution s;
    string str = "    the    sky    is   blue   ";
    s.reverseWords(str);
    assert(str == "blue is sky the");

    string str1 = " ";
    s.reverseWords(str1);
    assert(str1 == "");
}

int main(int argc, char *argv[]) {
    runTests();
}