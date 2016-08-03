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
    Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
    Visually, the graph looks like the following:

        1
       / \
      /   \
     0 --- 2
          / \
          \_/
*/

/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/


struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    UndirectedGraphNode* visit(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& graph)
    {
        if (graph.find(node) == graph.end())
        {
            graph[node] = new UndirectedGraphNode(node->label);
            for (auto neighbour : node->neighbors)
            {
                graph[node]->neighbors.push_back(visit(neighbour, graph));
            }
        }
        return graph[node];
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> graph;
        return visit(node, graph);
    }
};

void runTests()
{
    Solution s;
}
int main(int argc, char *argv[]) {

    runTests();
}