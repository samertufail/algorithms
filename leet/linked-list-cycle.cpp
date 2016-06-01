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
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}  
};

class Solution {
public:
    bool hasCycleWExtraSpace(ListNode *head) {
        if (!head) return false;
        unordered_set<ListNode*> map;
        ListNode* iter = head;
        while (iter)
        {
            if (map.find(iter) != map.end()) return true;
            else map.insert(iter);
            iter = iter->next;
        }
        return false;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr, *next = nullptr;
        while (head)
        {
            next = head->next;  
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool hasCycleWoExtraSpace(ListNode* head)
    {
        if (!head) return false;

        return (head == reverseList(head));
    }
};

void runTestNoCycle()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(8);
    Solution s;
    assert(false == s.hasCycleWoExtraSpace(head));
    assert(false == s.hasCycleWExtraSpace(head));
}

void runTestWithCycle()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head->next;

    Solution s;
    assert(true == s.hasCycleWoExtraSpace(head));
    assert(true == s.hasCycleWExtraSpace(head));
}

int main(int argc, char *argv[]) {
    runTestNoCycle(); runTestWithCycle();
}