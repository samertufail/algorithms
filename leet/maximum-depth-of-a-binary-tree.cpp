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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

class Solution {
private:
	int getDepth(TreeNode* root, int depth)
	{
		if (root == NULL) return depth;
		depth = max(getDepth(root->left, depth + 1), getDepth(root->right, depth + 1));
		return depth;
	}
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return getDepth(root, 0);
	}
};

void assertHelper(int actual, int expected)
{
	assert(actual == expected);
}
void testEmpty() {
	Solution s;
	TreeNode* root = nullptr;
	assertHelper(s.maxDepth(root), 0);
}
void testLeftGreater() {
	Solution s;
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(5);
	root->left->left->left = new TreeNode(12);
	root->left->left->left->left = new TreeNode(21);
	assertHelper(s.maxDepth(root), 5);
}
void testRightGreater() {
	Solution s;
	TreeNode* root = new TreeNode(8);
	root->right = new TreeNode(10);
	root->right->right = new TreeNode(5);
	root->right->right->right = new TreeNode(12);
	assertHelper(s.maxDepth(root), 4);
}
void testBalanced() {
	Solution s;
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->right = new TreeNode(10);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(6);
	assertHelper(s.maxDepth(root), 3);
}
int main(int argc, char *argv[]) {
	testEmpty(); testLeftGreater(); testRightGreater(); testBalanced();
}