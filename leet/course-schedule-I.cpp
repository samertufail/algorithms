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
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs,
is it possible for you to finish all courses?

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0,
and to take course 0 you should also have finished course 1. So it is impossible.
*/


class Solution {
private:
    bool visit(int node, unordered_map<int, vector<int>>& graph, vector<int>& visited)
    {
        if (visited[node] == 1) return false;
        if (visited[node] == 2) return true;
        visited[node] = 1;
        vector<int> adj = graph[node];
        for (int v : adj) if (!visit(v, graph, visited)) return false;
        visited[node] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> visited(numCourses, 0);
        for (auto preq : prerequisites) graph[preq.first].push_back(preq.second);
        for (int i = 0; i < numCourses; ++i)
        {
            if (!visit(i, graph, visited)) return false;
        }
        return true;
    }
};

void runTests()
{
    Solution s;
    vector<pair<int, int>> preqse1 = { {1,0} };
    assert(true == s.canFinish(2, preqse1));

    vector<pair<int, int>> preqse2 = { { 1,0 }, {0,1} };
    assert(false == s.canFinish(2, preqse2));

    vector<pair<int, int>> preqse3 = { { 1,0 },{ 2,0 } };
    assert(true == s.canFinish(3, preqse3));

    vector<pair<int, int>> preqse4 = { { 0, 1 },{ 1, 2 }, {0,3}, {3,0} };
    assert(false == s.canFinish(4, preqse4));

    vector<pair<int, int>> preqse5 = { { 0, 1 },{ 0, 2 }, {1,2} };
    assert(true == s.canFinish(3, preqse5));
}
int main(int argc, char *argv[]) {

    runTests();
}