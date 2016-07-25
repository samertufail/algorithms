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
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to],
reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. 
Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read 
as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.

tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
*/


class Solution {
private:
    void visit(string to, vector<string>& iter, unordered_map<string, multiset<string>>& graph)
    {
        while (graph[to].size() != 0)
        {
            string vertex = *(graph[to].begin());
            graph[to].erase(graph[to].begin());
            visit(vertex, iter, graph);
        }
        iter.push_back(to);
    }

public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto ticket : tickets) graph[ticket.first].insert(ticket.second);
        vector<string> iter;
        visit("JFK", iter, graph);
        reverse(iter.begin(), iter.end());
        return iter;
    }
};

void runTests()
{
    Solution s;
    vector<pair<string, string>> ticketse1 = { {"MUC","LHR"}, {"JFK","MUC"}, {"SFO","SJC"}, {"LHR","SFO"} };
    vector<string> ticketse1Expected = { "JFK", "MUC", "LHR", "SFO", "SJC" };
    assert(ticketse1Expected == s.findItinerary(ticketse1));

    vector<pair<string, string>> ticketse2 = { {"JFK", "SFO"},{"JFK", "ATL"},{"SFO", "ATL"},{"ATL", "JFK"},{"ATL", "SFO"} };
    vector<string> ticketse2Expected = { "JFK","ATL","JFK","SFO","ATL","SFO" };
    assert(ticketse2Expected == s.findItinerary(ticketse2));
}
int main(int argc, char *argv[]) {
    runTests();
}