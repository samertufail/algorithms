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
using namespace std;

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it 
can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later 
in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work.
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the
original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"

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

class Codec {
public:
    string serialhelper(TreeNode* root)
    {
        if (!root) return "x";
        return to_string(root->val) + ',' + serialhelper(root->left) + "," + serialhelper(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        return serialhelper(root);
    }

    int parser(string& str)
    {
        size_t found = str.find_first_of(',');
        int val = stoi(str.substr(0, found));
        str = str.substr(found + 1);
        return val;
    }
    TreeNode* deserialhelper(string& str)
    {
        if (str[0] == 'x')
        {
            if (str.size() > 1) str = str.substr(2);
            return nullptr;
        }

        TreeNode* node = new TreeNode(parser(str));
        node->left = deserialhelper(str);
        node->right = deserialhelper(str);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        return deserialhelper(data);
    }
};

void runTests()
{
    Codec code;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string str = code.serialize(root);
    TreeNode* rootnew = code.deserialize(str);
}

int main(int argc, char *argv[]) {
    runTests();
}