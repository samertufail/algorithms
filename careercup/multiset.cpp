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
using namespace std;

/*
A multiset or a bag is a collection of elements that can be repeated. Contrast with a set, where elements cannot be repeated.
Multisets can be intersected just like sets can be intersected.

Input :
A = [0,1,1,2,2,5]
B = [0,1,2,2,2,6]

Output :
A n B = C = [0,1,2,2]

Input :
A = [0,1,1]
B = [0,1,2,3,4,5,6]

Output
A n B = C = [0,1]

Write a function to find the intersection of two integer arrays in that way ?
*/

class Solution {
public:
    vector<int> multiSet(vector<int>& arr1, vector<int>& arr2)
    {
        int n1 = arr1.size(); int n2 = arr2.size();
        if (n1 == 0 && n2 == 0) return {};
        if (n1 == 0) return arr2; 
        if (n2 == 0) return arr1;

        int len = 0; vector<int> res = {};

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        len = n1 > n2 ? n2 : n1;
        
        for (int i = 0; i < len; ++i)
        {
            if (arr1[i] == arr2[i])
                res.push_back(arr1[i]);
        }

        return res;
    }
};

void runTestEmpty()
{
    Solution sol;
    vector<int> A = {}; vector<int> B = {};
    vector<int> C = sol.multiSet(A, B);
    assert(C.size() == 0);
}
void runGiven()
{
    Solution sol;
    vector<int> A = { 0,1,1,2,2,5 }; vector<int> B = { 0,1,2,2,2,6 };
    vector<int> CExpected = { 0,1,2,2 };
    vector<int> C = sol.multiSet(A, B);
    assert(C == CExpected);
}

void runBGreaterThanA()
{
    Solution sol;
    vector<int> A = { 0, 1, 1 }; vector<int> B = { 0, 1, 2, 3, 4, 5, 6 };
    vector<int> CExpected = { 0, 1 };
    vector<int> C = sol.multiSet(A, B);
    assert(C == CExpected);
}

void runAGreaterThanB()
{
    Solution sol;
    vector<int> B = { 0, 1, 1 }; vector<int> A = { 0, 1, 2, 3, 4, 5, 6 };
    vector<int> CExpected = { 0, 1 };
    vector<int> C = sol.multiSet(A, B);
    assert(C == CExpected);
}

void runUnsortedInputs()
{
    Solution sol;
    vector<int> B = { 1, 0, 1 }; vector<int> A = { 6,5,4,2,1,3,0 };
    vector<int> CExpected = { 0, 1 };
    vector<int> C = sol.multiSet(A, B);
    assert(C == CExpected);
}

int main(int argc, char *argv[]) {
    runTestEmpty();
    runGiven();
    runBGreaterThanA();
    runUnsortedInputs();
}