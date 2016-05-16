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
Write a function to test if the given set of brackets are balanced or not. e.g. {{}}{)([][]
*/

// Assuming empty string is balanced
class Solution {
public:
	bool isBalanced(string brackets) {
		int len = brackets.length();
		if (len == 0) return true;
		unordered_map<char, char> map;
		map['}'] = '{'; map[')'] = '('; map[']'] = '[';
		stack<char> bStack;

		for (int i = 0; i < len; ++i)
		{
			if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[') bStack.push(brackets[i]);
			else if (!bStack.empty() && map[brackets[i]] == bStack.top()) bStack.pop();
			else return false;
		}
		return bStack.empty();
	}
};

void runTests()
{
	Solution s;
	assert(s.isBalanced("") == true);
	assert(s.isBalanced("{{}}[][]") == true);
	assert(s.isBalanced("{{}[][]}") == true);
	assert(s.isBalanced("{{}}[][]") == true);
	assert(s.isBalanced(")(][") == false);
	assert(s.isBalanced("{[[[[[]]]]]}") == true);
}

int main(int argc, char *argv[]) {
	runTests();
}