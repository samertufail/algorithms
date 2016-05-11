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
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language.
For example,
Given the following words in dictionary,
[
"wrt",
"wrf",
"er",
"ett",
"rftt"
]
The correct order is: "wertf".
Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

class Solution {
private:
	bool visit(char node, unordered_map<char, unordered_set<char>>& g, unordered_map<char, int>& visited, string& res)
	{
		if (visited[node] == 1) return false;
		if (visited[node] == 2) return true;
		visited[node] = 1; // In Progress
		for (auto it = g[node].begin(); it != g[node].end(); ++it)
		{
			if (!visit(*it, g, visited, res)) return false;
		}
		visited[node] = 2; // Our visit is complete
		res = node + res;
		return true;
	}
public:
	string alienOrder(vector<string>& words) {
		unordered_map<char, unordered_set<char>> graph; string res;
		int len = words.size();
		// Create the graph here and nothing else - If we find the a mismatch add them as an edge else just a vertex of a graph
		for (int i = 1; i < len; ++i)
		{
			string wordPre = words[i - 1]; string wordNext = words[i];
			int length = max(wordPre.length(), wordNext.length());
			for (int j = 0; j < length; ++j)
			{
				if (j < wordPre.length() && graph.find(wordPre[j]) == graph.end()) graph[wordPre[j]] = unordered_set<char>({});
				if (j < wordNext.length() && graph.find(wordNext[j]) == graph.end()) graph[wordNext[j]] = unordered_set<char>({});
				if (j < wordPre.length() && j < wordNext.length() && wordPre[j] != wordNext[j])
				{
					// Stop where we find the first mismatch
					graph[wordPre[j]].insert(wordNext[j]);
					break;
				}
			}
		}

		// Start the topological sort here
		int gsize = graph.size(); auto end = graph.end();
		unordered_map<char, int> visited(gsize);
		for (auto it = graph.begin(); it != end; ++it)
		{
			if (!visit((*it).first, graph, visited, res)) return "";
		}

		return res;
	}
};

int main(int argc, char *argv[]) {
	//
}