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
using namespace std;

/* 
You are a product manager and currently leading a team to develop a new product. Unfortunately, 
the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API. 
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	// Binary search solution
    int firstBadVersion(int n) {
    	if (n == 0) return isBadVersion(n);
    	int i = 0, j = n, mid = 0;
    	while (i <= j)
    	{
    		mid = i + (j - i) / 2;
    		if (!isBadVersion(mid)) i = mid + 1;
    		else j = mid - 1;
    	}
    	return i;
    }
};