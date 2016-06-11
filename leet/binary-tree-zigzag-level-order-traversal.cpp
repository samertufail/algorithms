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
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

   3
  / \
 9  20
   /  \
  15   7

return its zigzag level order traversal as:

[
[3],
[20,9],
[15,7]
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
    void helper(TreeNode* node, int level, vector<vector<int>>& zigzag)
    {
        if (!node) return;
        if (zigzag.size() == level) zigzag.push_back({});
        zigzag[level].push_back(node->val);

        helper(node->left, level + 1, zigzag);
        helper(node->right, level + 1, zigzag);        
    }
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return{ };
        vector<vector<int>> zigzag = {};
        helper(root, 0, zigzag);

        for (int i = 0; i < zigzag.size(); ++i)
        {
            if (((i + 1) % 2) == 0)
            {
                reverse(zigzag[i].begin(), zigzag[i].end());
            }
        }

        return zigzag;
    }
};

void runTests()
{
    Solution s;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    s.zigzagLevelOrder(root);

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);
    s.zigzagLevelOrder(root1);
}

int main(int argc, char *argv[]) {
    runTests();
}