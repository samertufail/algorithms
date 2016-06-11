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
using namespace std;

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

             5
            / \
           4   8
          /   / \
         11  13  4
        /  \    / \
       7    2  5   1

return

[
[5,4,11,2],
[5,8,4,5]
]

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
private:
    void helper(TreeNode* node, int target, int sum, vector<vector<int>>& vec, vector<int>& path)
    {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right && sum + node->val == target) vec.push_back(path);

        helper(node->left, target, sum + node->val, vec, path);
        helper(node->right, target, sum + node->val, vec, path);
        path.pop_back();
    }
public:

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return{};
        vector<vector<int>> paths;
        vector<int> path;
        helper(root, sum, 0, paths, path);
        return paths;
    }
};

void runTests()
{
    /*       5
            / \
           4   8
          /   / \
         11  13  4
        /  \    / \
       7    2  5   1
       */
    Solution s;

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(7);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    s.pathSum(root, 22);

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    s.pathSum(root1, 1);
}

int main(int argc, char *argv[]) {
    runTests();
}