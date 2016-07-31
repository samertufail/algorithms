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
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them.
If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]

There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
Another correct ordering is[0,2,1,3].
*/


class Solution {
private:
    bool visit(int node, unordered_map<int, vector<int>>& graph, vector<int>& visited, vector<int>& result)
    {
        if (visited[node] == 1) return false;
        if (visited[node] == 2) return true;
        visited[node] = 1;
        vector<int> adj = graph[node];

        for (int node : adj) if (!visit(node, graph, visited, result)) return false;

        visited[node] = 2;
        result.push_back(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        unordered_map<int, vector<int>> graph;
        vector<int> visited(numCourses, 0);
        vector<int> result;
        for (pair<int, int>& preq : prerequisites) graph[preq.first].push_back(preq.second);

        for (int i = 0; i < numCourses; ++i)
        {
            if (!visit(i, graph, visited, result)) return{};
        }

        return result;
    }
};

void runTests()
{
    Solution s;
    vector<pair<int, int>> preqse1 = { {1,0},{2,0},{3,1},{3,2} };
    vector<int> resulte1 = { 0,1,2,3 };
    assert(resulte1 == s.findOrder(4, preqse1));

    vector<pair<int, int>> preqse2 = { { 0,1 },{ 1,0 } };
    vector<int> resulte2 = { };
    assert(resulte2 == s.findOrder(2, preqse2));
}
int main(int argc, char *argv[]) {

    runTests();
}