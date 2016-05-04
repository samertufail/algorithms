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

/*Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2.Please note that your returned answers(both index1 and index2)
are not zero - based.*/

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size(); if (len < 1) return{};
		int start = 0; int end = len - 1;
		while (start <= end)
		{
			if (numbers[end] + numbers[start] == target) { return{ start + 1, end + 1 }; }
			else if (numbers[end] + numbers[start] < target) ++start;
			else --end;
		}

		return{};
	}
};
int main(int argc, char *argv[]) {
	const int target = 9; vector<int> numbers = { 2, 7, 11, 15 }; Solution s;
	vector<int> res = s.twoSum(numbers, 9);
	assert(res[0] == 1 && res[1] == 2);
}