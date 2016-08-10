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
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

    [
      [1,2],
      [3],
      [4,5,6]
    ]

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

*/

class Vector2D {
private:
    int row;
    int col;
    vector<vector<int>> vec2d;
public:
    Vector2D(vector<vector<int>>& vec2d) : row(0), col(0), vec2d(vec2d) {

    }

    int next() {
        return vec2d[row][col++];
    }

    bool hasNext() {
        while (row < vec2d.size() && vec2d[row].size() == col) ++row, col = 0;
        return row < vec2d.size();
    }
};


/**
* Your Vector2D object will be instantiated and called as such:
* Vector2D i(vec2d);
* while (i.hasNext()) cout << i.next();
*/

void runTests()
{
    vector<vector<int>> vec2d1 = { { }, { }, {-1} };
    vector<int> ex1 = { -1 };
    vector<int> act1;
    Vector2D i1(vec2d1);
    while (i1.hasNext()) act1.push_back(i1.next());
    assert(ex1 == act1);

    vector<vector<int>> vec2d2 = { {1,2},{3},{4,5,6} };
    vector<int> ex2 = { 1,2,3,4,5,6 };
    vector<int> act2;
    Vector2D i2(vec2d2);
    while (i2.hasNext()) act2.push_back(i2.next());
    assert(ex2 == act2);
}

int main(int argc, char *argv[]) {

    runTests();
}