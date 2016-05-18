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
using namespace std;

/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
	int mySqrt(int x) {
		if (x < 0) return INT_MIN;
		if (x == 0) return 0;
		int left = 1; int right = x; int mid = 0; int res = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (mid == x / mid) return mid;
			else if (mid > x / mid) right = mid - 1;
			else
			{
				left = mid + 1;
				res = mid;
			}
		}

		return res;
	}
};

void runTests()
{
	Solution s;
	assert(s.mySqrt(0) == 0);
	assert(s.mySqrt(-1) == INT_MIN);
	assert(s.mySqrt(INT_MAX) == 46340);
	assert(s.mySqrt(4) == 2);
	assert(s.mySqrt(9) == 3);
}

int main(int argc, char *argv[]) {
	runTests();
}