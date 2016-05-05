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

/* Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells
are those horizontally or vertically neighboring. The same letter cell may not be used more than once. */

class Solution {
private:
	bool visitNodes(vector<vector<char>>& board, int row, int col, string word)
	{
		if (word == "") { return true; }
		else
		{
			if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0) { return false; }
			if (word[0] == board[row][col])
			{
				// mark visited and do a depth first from that point on
				char ch = word[0]; board[row][col] = 'x';
				if (visitNodes(board, row - 1, col, word.substr(1)) ||
					visitNodes(board, row + 1, col, word.substr(1)) ||
					visitNodes(board, row, col - 1, word.substr(1)) ||
					visitNodes(board, row, col + 1, word.substr(1))) return true;
				board[row][col] = ch;
			}
			return false;
		}
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return false;
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (visitNodes(board, i, j, word)) return true;
			}
		}
		return false;
	}
};

bool testCombinations(string toTest) {
	vector<vector<char>> board = { { 'A','B','C','E' },
								   { 'S','F','C','S' },
								   { 'A','D','E','E' } };
	Solution s; return s.exist(board, toTest);
}
int main(int argc, char *argv[]) {
	assert(testCombinations("")       == false);
	assert(testCombinations("ABCCED") == true);
	assert(testCombinations("SEE")    == true);
	assert(testCombinations("ABCB")   == false);
}