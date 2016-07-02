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
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.

For example,
Given the following binary tree,

    1
   /  \
  2    3
 / \    \
4   5    7

After calling your function, the tree should look like:

    1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL

*/

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode* head, *tail;

        while (root)
        {
            head = tail = nullptr;
            while (root)
            {
                if (root->left)
                {
                    if (!head) head = root->left;
                    if (tail) tail->next = root->left;
                    tail = root->left;
                }
                if (root->right)
                {
                    if (!head) head = root->right;
                    if (tail) tail->next = root->right;
                    tail = root->right;
                }
                root = root->next;
            }
            root = head;
        }
    }
};

void runTests()
{

}

int main(int argc, char *argv[]) {
    runTests();
}