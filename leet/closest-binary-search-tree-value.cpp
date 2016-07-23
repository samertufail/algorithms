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
using namespace std;

/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void traverse(TreeNode* root, double target, double& curr)
    {
        if (!root) return;
        if (abs((double)root->val - target) < abs(target - curr)) curr = root->val;
        if ((double)root->val < target)
            traverse(root->right, target, curr);
        else if ((double)root->val > target)
            traverse(root->left , target, curr);
    }

    int closestValue(TreeNode* root, double target) {
        double val = root->val;
        traverse(root, target, val);
        return (int)val;
    }
};

void runTests()
{
    Solution s;
}

int main(int argc, char *argv[]) {

    runTests();
}