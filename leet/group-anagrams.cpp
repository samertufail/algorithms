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
Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]   
*/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		typedef unordered_map<string, vector<string>> vmap;
		vmap map; int n = strs.size();

		for (int i = 0; i < n; ++i)
		{
			string temp = strs[i]; sort(temp.begin(), temp.end());
			map[temp].push_back(strs[i]);
		}

		vector<vector<string>> res(map.size()); int i = 0;
		for (vmap::iterator iter = map.begin(); iter != map.end(); ++iter, ++i)
		{
			sort((*iter).second.begin(), (*iter).second.end()); // sort lexiographic order
			res[i] = (*iter).second;
		}

		return res;
	}
};

void testGiven() {
	Solution s;
	vector<string> given = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> expected = { {"ate", "eat", "tea"},
										{"nat", "tan"},
										{"bat"} };
	vector<vector<string>> actual   = s.groupAnagrams(given);
	assert(equal(expected.begin(), expected.end(), actual.begin(), actual.end()));
}
void testEmpty() {
	Solution s;
	vector<string> given = { };
	vector<vector<string>> expected = { };
	vector<vector<string>> actual = s.groupAnagrams(given);
	assert(equal(expected.begin(), expected.end(), actual.begin(), actual.end()));
}

int main(int argc, char *argv[]) {
	testEmpty();
	testGiven();
}