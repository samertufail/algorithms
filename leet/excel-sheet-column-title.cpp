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
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
*/

class Solution {
public:
    string convertToTitle(int n) {
        if (n == 0) return ""; string res;
        while (n)
        {
            res += 'A' + (n - 1) % 26;
            n = (n - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void runTests()
{
    Solution sol;
    assert("" == sol.convertToTitle(0));
    assert("C" == sol.convertToTitle(3));
    assert("AB" == sol.convertToTitle(28));
}

int main(int argc, char *argv[]) {
    runTests();
}