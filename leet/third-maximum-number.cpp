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
#include <iomanip>
using namespace std;

/*
Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number.

The time complexity must be in O(n).
*/

class Solution {
public:
    int thirdMax(vector<int> nums) {
        long long fmax = LLONG_MIN, smax = LLONG_MIN, tmax = LLONG_MIN;
        for (int x : nums) fmax = std::max<long long>(fmax, x);
        for (int y : nums) if (y != fmax) smax = std::max<long long>(smax, y);
        for (int z : nums) if (z != smax && z != fmax) tmax = std::max<long long>(tmax, z);

        return (tmax == LLONG_MIN) ? fmax : tmax;
    }
};

void runTests()
{
    Solution s;
    assert(s.thirdMax(vector<int>({ 3,2,1 })) == 1);
    assert(s.thirdMax(vector<int>({ 1,2 })) == 2);
    assert(s.thirdMax(vector<int>({ 2,2,3,1 })) == 1);
    assert(s.thirdMax(vector<int>({ 1, 2, INT_MIN })) == INT_MIN);
}

int main(int argc, char *argv[]) {

    runTests();
}