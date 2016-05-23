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
using namespace std;

/*
There's a very simple compression algorithm that takes subsequent characters and just emits how often they were seen.
Example:
abababaabbbaaaaa
*/

class Solution {
public:
    string compress(string str)
    {
        int len = str.length();
        if (len < 1) return str;
        string res = ""; 
        int count = 1;
        for (int i = 1; i < len; ++i)
        {
            if (str[i] != str[i - 1]) {
                count == 1 ? res += str[i - 1] : res += str[i - 1] + to_string(count);
                count = 1;
            }
            else ++count;
        }

        // add the last char set
        count == 1 ? res += str[len - 1] : res += str[len - 1] + to_string(count);
        return res;
    }
};

void runTests()
{
    Solution sol;
    assert("abababa2b3a5" == sol.compress("abababaabbbaaaaa"));
    assert("" == sol.compress(""));
    assert("abababa2b3a4c" == sol.compress("abababaabbbaaaac"));
    assert("ab" == sol.compress("ab"));
    assert("ab9c" == sol.compress("abbbbbbbbbc"));
}

int main(int argc, char *argv[]) {
    runTests();
}