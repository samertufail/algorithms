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
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that 
adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

                 5
                / \
               4   8
              /   / \
             11  13  4
            /  \    / \
           7    2  5   1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    bool helperHasSum(TreeNode* node, int sum, int target)
    {
        if (!node) return false;
        if (!node->left && !node->right && sum + node->val == target) return true;
        return helperHasSum(node->left, sum + node->val, target) || helperHasSum(node->right, sum + node->val, target);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return helperHasSum(root, 0, sum);
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

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);

    assert(true == s.hasPathSum(root, 22));
    assert(true == s.hasPathSum(root1, 3));
    assert(false == s.hasPathSum(root, 2));
    assert(false == s.hasPathSum(root, 10));
}

int main(int argc, char *argv[]) {
    runTests();
}