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
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the 
depth of the two subtrees of every node never differ by more than 1.

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool traverse(TreeNode* root, int& depth)
    {
        if (!root) {
            depth = 0; 
            return true;
        }
        int left, right;
        if (traverse(root->left, left) && traverse(root->right, right) && abs(left - right) <= 1) {
            depth = max(left, right) + 1;
            return true;
        }
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return traverse(root, depth);
    }
};

void runBalanced()
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    Solution s;
    assert(true == s.isBalanced(node));
}

void runNotBalanced()
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(5);
    node->left->right = new TreeNode(8);
    node->right->left = new TreeNode(10);


    Solution s;
    assert(true == s.isBalanced(node));
}

void runSingleDepth()
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    Solution s;
    assert(true == s.isBalanced(node));
}

int main(int argc, char *argv[]) {
    runBalanced(); runNotBalanced(); runSingleDepth();
}