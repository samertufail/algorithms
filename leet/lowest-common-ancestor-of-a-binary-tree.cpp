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

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).” */

class Solution {
private:
	bool helper(TreeNode* root, TreeNode* p)
	{
		if (root == NULL) return false;
		if (root == p) return true;
		return helper(root->left, p) || helper(root->right, p);
	}
	TreeNode* ancFinder(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == NULL || p == root || q == root) return root;

		bool pLeft = helper(root->left, p);
		bool qLeft = helper(root->left, q);
		if (pLeft != qLeft) return root;

		TreeNode* whichSide = pLeft ? root->left : root->right;
		return ancFinder(whichSide, p, q);
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL; if (p == NULL || q == NULL) return root;
		if (!helper(root, p) || !helper(root, q)) return NULL;
		return ancFinder(root, p, q);
	}
};

void testEmpty() {
	Solution s;
	TreeNode* root = nullptr;
	assert(s.lowestCommonAncestor(root, nullptr, nullptr) == nullptr);
}
void testLeftGreater() {
	Solution s;
	TreeNode* root = new TreeNode(8);
	TreeNode* right = root->left = new TreeNode(3);
	root->left->left = new TreeNode(5);
	root->left->left->left = new TreeNode(12);
	TreeNode* left = root->left->left->left->left = new TreeNode(21);
	assert(s.lowestCommonAncestor(root, left, right)->val == 3) ;
}
void testRightGreater() {
	Solution s;
	TreeNode* root = new TreeNode(8);
	TreeNode* right = root->right = new TreeNode(10);
	root->right->right = new TreeNode(5);
	TreeNode* left = root->right->right->right = new TreeNode(12);
	assert(s.lowestCommonAncestor(root, left, right)->val == 10);
}
void testBalanced() {
	Solution s;
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->right = new TreeNode(10);
	TreeNode* left = root->left->left = new TreeNode(1);
	TreeNode* right = root->left->right = new TreeNode(6);
	assert(s.lowestCommonAncestor(root, left, right)->val == 3);
}
int main(int argc, char *argv[]) {
	testEmpty(); testLeftGreater(); testRightGreater(); testBalanced();
}