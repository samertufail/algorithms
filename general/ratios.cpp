/*
Inputs:
A / B = 0.5
B / C = 0.6

Outputs:
A / C = ?
Tomato / Lemon = ?

AB=0.5, BC=0.6, AC=?

Inputs:
("A", "B", 0.5)
("B", "C", 0.6)
...

*/

struct vertex
{
    string node;
    double weight;
    vertex(string node, double weight) : node(node), weight(weight) { }
};

class Solution {
public:
    unordered_map<string, vector<vertex>> graph;
    void Add(string v1, string v2, double weight)
    {
        graph[v1].push_back(vertex(v2, weight));
        graph[v2].push_back(vertex(v1, 1 / weight));
    }

    double DFS(unordered_map<string, bool>& visited, double ans, string& start, string& end)
    {
        visited[start] = true;
        for (auto it : graph[start])
        {
            if (!visited[it.node])
            {
                ans *= it.weight;
                if (it.node == end) return ans;
                return DFS(visited, ans, it.node, end);
            }
        }
        return 1.0;
    }
    double CalculateRatio(string num, string den) {
        unordered_map<string, bool> visited;
        if (graph.find(num) == graph.end() && graph.find(den) == graph.end()) return 0.0;
        return DFS(visited, 1.0, num, den);
    }
};

void runTests()
{
    Solution s;

    s.Add("A", "B", 0.5);
    s.Add("B", "C", 0.6);
    assert(double(0.3) == s.CalculateRatio("A", "C"));
    assert(double(3.3) <= s.CalculateRatio("C", "A"));
}

int main(int argc, char *argv[]) {

    runTests(); getchar();
}