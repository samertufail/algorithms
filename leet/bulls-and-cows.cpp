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
using namespace std;

/*
You are playing the following Bulls and Cows game with your friend: 
You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret 
number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong 
position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> leftchars;

        int i = 0;
        while (i < secret.length())
        {
            if (secret[i] == guess[i])
            {
                secret.erase(i, 1); guess.erase(i, 1);
                ++bulls;
            }
            else
            {
                ++leftchars[secret[i]]; ++i;
            }
        }

        for (int i = 0; i < secret.length(); ++i)
        {
            if (leftchars.find(guess[i]) != leftchars.end() )
            {
                if (leftchars[guess[i]] != 0)
                {
                    --leftchars[guess[i]];
                    ++cows;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};


void runTests()
{
    Solution s;
    assert("0A4B" == s.getHint("1122", "2211"));
    assert("1A3B" == s.getHint("1807", "7810"));
}

int main(int argc, char *argv[]) {
    runTests();
}