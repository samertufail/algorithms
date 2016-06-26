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
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:

    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 1) return -1;

        int left = 0, right = len - 1;

        // Search for a pivot
        while (left < right)
        {
            if (nums[left] > nums[right]) { --right; }
            else break;
        }

        // Set the pivot to search left half
        int pivot = right;
        if (nums[pivot] == target) return pivot;

        int l = 0, r = pivot - 1, mid = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        // Set pivot to search right half
        l = pivot + 1, r = len - 1, mid = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
};

void runTests()
{
    Solution s;
    vector<int> vec = { 0,1,2,4,5,6,7 };
    rotate(vec.begin(), vec.begin() + 3, vec.end());
    assert(6 == s.search(vec, 2));

    vector<int> vec1 = { 0,1,2,4,5,6,7 };
    rotate(vec1.begin(), vec1.begin() + 2, vec1.end());
    assert(0 == s.search(vec1, 2));

    vector<int> vec3 = { 5,1,3 };
    assert(1 == s.search(vec3, 1));

    vector<int> vec4 = { 9,1,2,3,4,5,6,7,8 };
    assert(0 == s.search(vec4, 9));

    vector<int> vec5 = { 4, 5, 6, 7, 8, 1, 2, 3 };
    assert(4 == s.search(vec5, 8));
}

int main(int argc, char *argv[]) {
    runTests();
}