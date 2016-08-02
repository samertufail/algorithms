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
#include <numeric> 
#include <thread>
#include <memory>
#include <mutex>
#include <iomanip>
using namespace std;

/*
For a undirected graph with tree characteristics, we can choose any node as the root.
The result graph is then a rooted tree. Among all possible rooted trees,
those with minimum height are called minimum height trees (MHTs). 
Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. 
You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

     0
     |
     1
    / \
   2   3

return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

        0  1  2
         \ | /
           3
           |
           4
           |
           5

return [3, 4]
*/


class Solution {
private:
    int getHeight(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int node)
    {
        int maxh = 0;
        visited[node] = true;
        vector<int> adj = graph[node];
        for (auto i : adj)
        {
            if (!visited[i]) maxh = max(maxh, getHeight(graph, visited, i));
        }
        visited[node] = false;
        return maxh + 1;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> result;

        for (auto& edge : edges)
        {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        int curmin = INT_MAX;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            int h = getHeight(graph,visited, i);
            if (h < curmin)
            {
                result.clear();
                result.push_back(i);
                curmin = h;
            }
            else if (h == curmin) result.push_back(i);
        }

        return result;
    }
};

void runTests()
{
    Solution s;
    vector<pair<int, int>> edgest1 = { {1, 0 }, { 1, 2 }, { 1, 3 } };
    vector<int> edgese1 = { 1 };
    assert(edgese1 == s.findMinHeightTrees(4, edgest1));

    vector<pair<int, int>> edgest2 = { {0, 3},{1, 3},{2, 3},{4, 3},{5, 4} };
    vector<int> edgese2 = { 3,4 };
    assert(edgese2 == s.findMinHeightTrees(6, edgest2));
}
int main(int argc, char *argv[]) {

    runTests();
}