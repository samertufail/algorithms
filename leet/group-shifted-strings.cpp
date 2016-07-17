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
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". 
We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, 
group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
A solution is:

[
["abc","bcd","xyz"],
["az","ba"],
["acef"],
["a","z"]
]

*/

class Solution {
public:
    string encode(string str)
    {
        int key = str[0] - '#';
        for (char &c : str)
        {
            c = (c - key + 26) % 26 + '#';
        }
        return str;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        int len = strings.size();
        if (len == 0) return{};

        unordered_map<string, vector<string>> map;
        for (string str : strings)
        {
            map[encode(str)].push_back(str);
        }

        vector<vector<string>> res;
        for (auto &val : map)
        {
            sort(val.second.begin(), val.second.end());
            res.push_back(val.second);
        }

        return res;
    }
};

void runTests()
{
    Solution s;
    vector<string> strs = { "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
    s.groupStrings(strs);
}

int main(int argc, char *argv[]) {

    runTests();
}