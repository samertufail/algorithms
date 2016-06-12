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
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 = k = BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
How would you optimize the kthSmallest routine?

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
    void helperBasic(TreeNode* node, vector<int>& vec)
    {
        if (!node) return;
        helperBasic(node->left, vec);
        vec.push_back(node->val);
        helperBasic(node->right, vec);
    }

    void helper(TreeNode* node, int& k, int& val)
    {
        if (!node) return;
        helper(node->left, k, val);
        if (k == 0) return;
        val = node->val;
        helper(node->right, --k, val);
    }
public:
    int kthSmallestBasic(TreeNode* root, int k) {
        vector<int> vec;
        helperBasic(root, vec);

        return vec[k - 1];
    }

    int kthSmallest(TreeNode* root, int k) {
        int val;
        helper(root, k, val);

        return val;
    }
};

void runTests()
{
    /*       5
            / \
           4   8
          /   / \
         3   7   9
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution s;
    assert(4 == s.kthSmallestBasic(root, 2));
    assert(4 == s.kthSmallest(root, 2));
}

int main(int argc, char *argv[]) {
    runTests();
}