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
"Smart substring"
Write a function that takes maximum 30 characters from a string but without cutting the words.

Full description:
"Featuring stylish rooms and moorings for recreation boats, Room Mate Aitana is a designer hotel built in 2013 on an island in the IJ River in Amsterdam."

First 30 characters:
"Featuring stylish rooms and mo"

Smarter approach (max 30 characters, no words are broken):
"Featuring stylish rooms and"
*/

class Solution {
public:
    string smartSubString(string str)
    {
        int len = str.length();
        if (len == 0 || len < 30) return str;

        if (len != 30)
        {
            string toChop = str.substr(0, 30);
            size_t pos = toChop.find_last_of(' ');
            if (pos != string::npos)
            {
                return toChop = toChop.substr(0, pos);
            }
        }

        return str;
    }
};

void runTests()
{
    Solution sol;
    assert(sol.smartSubString("") == "");
    assert("Featuring stylish rooms and" == sol.smartSubString("Featuring stylish rooms and moorings for recreation boats,"
                                                                "Room Mate Aitana is a designer hotel built in 2013 on an "
                                                                "island in the IJ River in Amsterdam."));
    assert("Featuring stylish rooms and mo" == sol.smartSubString("Featuring stylish rooms and mo"));
}

int main(int argc, char *argv[]) {
    runTests();
}