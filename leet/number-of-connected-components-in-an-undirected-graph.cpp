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

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
write a function to find the number of connected components in an undirected graph.

Example 1:

0          3
|          |
1 --- 2    4

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:

0           4
|           |
1 --- 2 --- 3

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

*/

class Solution {
private:
    void dfs(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited)
    {
        if (visited[node]) return;
        else
        {
            visited[node] = true;
            vector<int> adj = graph[node];
            for (auto v : adj)
            {
                if (!visited[v]) dfs(v, graph, visited);
            }
        }
    }

public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n <= 0) return 0;
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(n, 0);

        for (auto edge : edges)
        {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i]) { ++result, dfs(i, graph, visited); }
        }

        return result;
    }
};

void runTests()
{
    Solution s;
    vector<pair<int, int>> c1 = { {0, 1},{1, 2},{3, 4} };
    assert(2 == s.countComponents(5,c1));

    vector<pair<int, int>> c2 = { {0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 4 } };
    assert(1 == s.countComponents(5, c2));
}

int main(int argc, char *argv[]) {

    runTests();
}