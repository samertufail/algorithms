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
Given a stream of characters (e.g. acacabcatghhellomvnsdb) and a list of words (e.g. ["aca","cat","hello","world"] )
find and display count of each and every word once the stream ends.
(Like : "aca" : 2 , "cat" : 1 , "hello" : 1 , "world" : 0 ).
*/

class Solution {
public:
	void wordCountBrute(string str, vector<string>& words) {
		int clockStart = clock();
		int listLen = words.size(); if (listLen < 1) return;
		int len = str.length(); if (len < 1) return;
		int count = 0, wordlen = 0; string toFind;
		for (int i = 0; i < listLen; ++i)
		{
			toFind = words[i]; wordlen = words[i].size(), count = 0;
			for (int j = 0, k = 0; j < len; ++j)
			{
				while (j < len && str[j + k] == toFind[k]) ++k;
				if (k == wordlen) ++count;
				k = 0;
			}
			cout << toFind << ":" << count << endl;
		}
		int clockEnd = clock();
		cout << "Execution Time Without Map:" << (clockEnd - clockStart) / double(CLOCKS_PER_SEC) * 1000 << "ms" <<  endl;
	}

	void wordCountUsingMap(string str, vector<string>& words) {
		int clockStart = clock();
		int listLen = words.size(); if (listLen < 1) return;
		int len = str.length(); if (len < 1) return;
		unordered_map<string, int> map;
		for (int i = 0; i < listLen; ++i) map[words[i]] = 0;
		
		for (int i = 0; i < listLen; ++i)
		{
			int wordLen = words[i].length(); string toFind = words[i], temp;
			for (int j = 0; j < len; ++j)
			{
				temp = str.substr(j, wordLen);
				if (temp == toFind) ++map[toFind];
			}
		}

		for (auto it = map.begin(); it != map.end(); ++it)
		{
			cout << (*it).first << ":" << (*it).second << endl;
		}

		int clockEnd = clock();
		cout << "Execution Time With Map:" << (clockEnd - clockStart) / double(CLOCKS_PER_SEC) * 1000 << "ms" << endl;
	}
};

void testGivenBrute()
{
	Solution s;
	vector<string> words = { "aca","cat","hello","world" };
	s.wordCountBrute("acacabcatghhellomvnsdb", words);
}
void testGivenMap()
{
	Solution s;
	vector<string> words = { "aca","cat","hello","world" };
	s.wordCountUsingMap("acacabcatghhellomvnsdb", words);
}
int main(int argc, char *argv[]) {
	testGivenBrute();
	testGivenMap();
	getchar();
}