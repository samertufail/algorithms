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
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

Not Symmetric:

  1
 / \
2   2
 \   \
  3   3

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool traverse(TreeNode* left, TreeNode* right)
    {
        if (!left && !right) return true;
        if (!left && right) return false;
        if (!right && left) return false;
        if (left->val != right->val) return false;

        return traverse(left->left, right->right) && traverse(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return traverse(root->left, root->right);
    }
};

void runTestSymmetric()
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(2);
    node->left->left = new TreeNode(3);
    node->left->right = new TreeNode(4);
    node->right->left = new TreeNode(4);
    node->right->right = new TreeNode(3);

    Solution s;
    assert(true == s.isSymmetric(node));
}

void runTestAsym()
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(2);
    node->left->right = new TreeNode(3);
    node->right->right = new TreeNode(3);

    Solution s;
    assert(false == s.isSymmetric(node));
}

int main(int argc, char *argv[]) {
    runTestSymmetric(); runTestAsym();
}