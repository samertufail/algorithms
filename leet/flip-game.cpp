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
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -,
you and your friend take turns to flip two consecutive "++" into "--".
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:

[
"--++",
"+--+",
"++--"
]

*/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int len = s.length();
        if (len == 0 || len < 2) return{};

        vector<string> res;
        for (int i = 0; i < len - 1; ++i)
        {
            if (s[i] == '+' && s[i + 1] == '+')
            {
                s[i] = s[i + 1] = '-';
                res.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return res;
    }

};

void runTests()
{
    Solution s;
}

int main(int argc, char *argv[]) {

    runTests();
}