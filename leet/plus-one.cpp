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
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if (len == 0) return{};
        bool process = true;

        for (int i = len - 1; i >= 0 && process; --i)
        {
            process = (++digits[i] %= 10) == 0;
        }

        if (process) digits.insert(digits.begin(), 1);

        return digits;
    }
};

void runTests()
{
    Solution s;
    vector<int> setone = { 1,2,3,4 }, expectedone = { 1,2,3,5 };
    assert(expectedone == s.plusOne(setone));

    vector<int> settwo = { 9,9,9,9 }, expectedtwo = { 1,0,0,0,0 };
    assert(expectedtwo == s.plusOne(settwo));

    vector<int> settthree = { 5,9,9,9 }, expectedthree = { 6,0,0,0 };
    assert(expectedthree == s.plusOne(settthree));

    vector<int> setfour = { 9,9,9,9 }, expectedfour = { 1,0,0,0,0 };
    assert(expectedfour == s.plusOne(setfour));

}

int main(int argc, char *argv[]) {

    runTests();
}