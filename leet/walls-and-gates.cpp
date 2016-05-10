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

/*  You are given a m x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4*/

class Solution {
private:
	void visitNodes(vector<vector<int>>& rooms, int row, int col, int distance)
	{
		if (row >= rooms.size() || row < 0 || col >= rooms[0].size() || col < 0 || rooms[row][col] == -1) return;
		if (distance <= rooms[row][col])
		{
			rooms[row][col] = distance;
			visitNodes(rooms, row + 1, col, distance + 1);
			visitNodes(rooms, row - 1, col, distance + 1);
			visitNodes(rooms, row, col + 1, distance + 1);
			visitNodes(rooms, row, col - 1, distance + 1);
		}
	}
public:
	void wallsAndGates(vector<vector<int>>& rooms) {

		if (rooms.size() < 1 || rooms[0].size() < 1) return;
		for (int i = 0; i < rooms.size(); ++i)
		{
			for (int j = 0; j < rooms[0].size(); ++j)
			{
				if (rooms[i][j] == 0) { visitNodes(rooms, i, j, 0); }
			}
		}
	}
};

int main(int argc, char *argv[]) {

}