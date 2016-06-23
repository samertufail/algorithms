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
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}    
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if (!head || !head->next) return nullptr;
        ListNode* slw = head;
        ListNode* fst = head;

        while (slw && fst)
        {
            slw = slw->next;
            if (fst->next == nullptr) return nullptr;
            fst = fst->next->next;
            if (slw == fst) break;
        }

        if (fst == nullptr) return nullptr;

        fst = head;
        while (slw != fst)
        {
            slw = slw->next;
            fst = fst->next;
        }

        return slw;
    }
};

void runTests()
{
    Solution s;
    
    ListNode* head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->next = new ListNode(5);
    head->next->next->next = head;
    assert(2 == s.detectCycle(head)->val);
}

int main(int argc, char *argv[]) {
    runTests();
}