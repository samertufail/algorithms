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
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

// The solution below will work on lower case, upper case and unicode it is type agnostic.
class Solution {
public:
	bool isAnagram(string s, string t) {

		int leftLen = s.length(), rightLen = t.length();
		if (leftLen == 0 && rightLen == 0) return true;
		if (leftLen != rightLen) return false; //left right are not equal no point

		typedef unordered_map<char, int> mtype; mtype map;
		for (int i = 0; i < leftLen; ++i) { if (map.find(s[i]) != map.end()) ++map[s[i]]; else map[s[i]] = 1; }
		for (int i = 0; i < rightLen; ++i) { if (map.find(t[i]) != map.end()) --map[t[i]]; else return false; }
		for (mtype::iterator it = map.begin(); it != map.end(); ++it) { if ((*it).second != 0) return false; }

		return true;
	}
};

void runTests() {
	Solution s;
	assert(s.isAnagram("", ""));
	assert(s.isAnagram("google", "microsoft") == 0);
	assert(s.isAnagram("rat", "car") == 0);
	assert(s.isAnagram("google", "elgoog"));
	assert(s.isAnagram("    ", "    "));
	assert(s.isAnagram("$#%@#", "#$#@%"));
}

int main(int argc, char *argv[]) {
	runTests();
}