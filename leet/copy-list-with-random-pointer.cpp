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
using namespace std;

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:

    // 1 -> 2 -> 3 -> 4 -> 5
    // p    p    p    p    p
    // 3    1    4    5    2

    // Map:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;

        RandomListNode* curr = head, *pre = nullptr, tail(0);
        unordered_map<RandomListNode*, RandomListNode*> map;
        pre = &tail;

        while (curr)
        {
            pre->next = new RandomListNode(curr->label);
            map[curr] = pre->next;
            pre = pre->next;
            curr = curr->next;
        }

        curr = head; pre = tail.next;

        while (curr)
        {
            pre->random = map[curr->random];
            pre = pre->next;
            curr = curr->next;
        }

        return tail.next;
    }

    //Interleaving
    // step 1: 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> 5
    //         p         p         p         p         p
    //         3         1         4         5         2

    RandomListNode *copyRandomListConstantSpace(RandomListNode *head) {
        if (!head) return nullptr;

        RandomListNode* curr = head, *next = nullptr;

        // Interleave List
        while (curr)
        {
            next = curr->next;
            curr->next = new RandomListNode(curr->label);
            curr->next->next = next;
            curr = next;
        }

        // Set random pointers
        curr = head;
        while (curr)
        {
            curr->next->random = curr->random == nullptr ? nullptr : curr->random->next;
            curr = curr->next->next;
        }

        // Restore create new list
        curr = head, next = nullptr;
        RandomListNode* pre = nullptr, tail(0);
        pre = &tail;
        while (curr)
        {
            next = curr->next;
            curr->next = curr->next->next;
            pre->next = next;
            pre = pre->next;
            curr = curr->next;
        }

        return tail.next;
    }
};

void runTests()
{
    Solution s;
    
    RandomListNode* head = new RandomListNode(2);
    head->next = new RandomListNode(3);
    head->next->next = new RandomListNode(5);
    s.copyRandomListConstantSpace(head);
}

int main(int argc, char *argv[]) {
    runTests();
}