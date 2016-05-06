#include "stdafx.h"
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

/* Write a function that takes a string as input and reverse only the vowels of a string.   */

class Solution {
public:
	string reverseVowels(string s) {
		int len = s.length(); if (len == 0) return "";
		int start = 0, end = len - 1; string res = s;
		unordered_set<char> dict = { 'a','e','i','o','u','A','E','I','O','U' };
		while (start < end)
		{
			while (start < end && dict.find(res[start]) == dict.end()) start++;
			while (start < end && dict.find(res[end]) == dict.end()) end--;
			swap(res[start], res[end]);
			++start; --end;
		}
		return res;
	}
};

void testEmpty() {
	Solution s;
	assert(s.reverseVowels("") == "");
}
void testValidVowels() {
	Solution s;
	assert(s.reverseVowels("source code") == "seorce cudo");
}
void testNoVowels() {
	Solution s;
	assert(s.reverseVowels("bt lt kt") == "bt lt kt");
}
void testAllSpaces() {
	Solution s;
	assert(s.reverseVowels("       ") == "       ");
}
void testUpperAndLowerCase() {
	Solution s;
	assert(s.reverseVowels("HeLlO") == "HOLle");
}

int main(int argc, char *argv[]) {
	testEmpty();
	testValidVowels();
	testNoVowels();
	testAllSpaces();
	testUpperAndLowerCase();
}