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
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:

The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        if (len1 < 1 || len2 < 1) return "0";

        string sum(num1.size() + num2.size(), '0'); // Space for the new number cant exceed the size of both
        for (int i = len1 - 1; i >= 0; --i)
        {
            // Multiply digit by digit store add the carry, take remainder
            int carry = 0;
            for (int j = len2 - 1; j >= 0; --j)
            {
                int res = (sum[i + j + 1] - '0') + ((num1[i] - '0') * (num2[j] - '0')) + carry;
                sum[i + j + 1] = (res % 10) + '0';
                carry = res / 10;
            }
            sum[i] = carry + '0';
        }

        // Remove any starting 0's we might have had
        size_t pos = sum.find_first_not_of('0');
        if (pos != string::npos) { return sum.substr(pos); }

        return "0";
    }
};

void runTests()
{
    Solution sol;
    assert("0" == sol.multiply("", ""));
    assert("62" == sol.multiply("31", "2"));
    assert("3875" == sol.multiply("155", "25"));
    assert("18446744073709551616" == sol.multiply("4294967296", "4294967296"));
}

int main(int argc, char *argv[]) {
    runTests();
}