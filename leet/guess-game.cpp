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
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {

        int l = 0, m = 0, r = n, g = 0;

        while (l <= r)
        {
            m = l + (r - l) / 2;
            g = guess(m);
            if (g == 0) return m;
            else if (g == -1) r = m - 1;
            else l = m + 1;
        }
        return 0;
    }
};

void runTests()
{
    Solution s;
}

int main(int argc, char *argv[]) {

    runTests();
}