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
Implement atoi to convert a string to an integer.

*/

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int pos = str.find_first_not_of(' ');

        bool isNegative = (str[pos] == '-');

        pos = (str[pos] == '+' || str[pos] == '-') ? pos + 1 : pos; int len = str.length();
        while (str[pos] == '0') ++pos;

        if (pos >= len) return 0;
        int num = 0;
        for (int i = pos, digits = 0; i < len && isdigit(str[i]); ++i, ++digits)
        {
            if (digits < 10)
            {
                if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > 7)) {
                    if (isNegative) return INT_MIN;
                    else return INT_MAX;
                }
                num = (str[i] - '0') + (num * 10);
            }
            else
            {
                return isNegative ? INT_MIN : INT_MAX;
            }
        }

        return isNegative ? num * -1 : num;
    }
};

void runTests()
{
    Solution s;
    assert(s.myAtoi("253") == atoi("253"));
    assert(s.myAtoi("00253") == atoi("00253"));
    assert(s.myAtoi("-00253") == atoi("-00253"));
    assert(s.myAtoi("13S#$^") == atoi("13S#$^"));
    assert(s.myAtoi("%$^4") == atoi("%$^4"));
    assert(s.myAtoi("----") == atoi("----"));
    assert(s.myAtoi("12345678911111111222222") == atoi("12345678911111111222222"));
    assert(s.myAtoi("-12345678911111111222222") == atoi("-12345678911111111222222"));
    assert(s.myAtoi("-523") == atoi("-523"));
    assert(s.myAtoi("5-23") == atoi("5-23"));
    assert(s.myAtoi("+1") == atoi("+1"));
    assert(s.myAtoi("    010") == atoi("    010"));
    assert(s.myAtoi("     +00329") == atoi("     +00329"));
    assert(s.myAtoi("2147483648") == atoi("2147483648"));
    assert(s.myAtoi("-2147483648") == atoi("-2147483648"));
    assert(s.myAtoi("-2147483649") == atoi("-2147483649"));
    assert(s.myAtoi("-2147483647") == atoi("-2147483647"));
}

int main(int argc, char *argv[]) {
    runTests();
}