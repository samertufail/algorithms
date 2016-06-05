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
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        int maxprofit = 0, minp = 0;
        for (int i = 1; i < len; ++i)
        {
            minp = prices[i] - prices[i - 1];
            if (minp > 0) maxprofit += minp;
        }
        return maxprofit;
    }
};

void runTests()
{
    Solution s;
    vector<int> p1 = { 5,4,1,2,8,9 };
    assert(8 == s.maxProfit(p1));

    vector<int> p2 = { 2,1};
    assert(0 == s.maxProfit(p2));

    vector<int> p3 = { 2,1,2,0,1 };
    assert(2 == s.maxProfit(p3));
}

int main(int argc, char *argv[]) {
    runTests();
}