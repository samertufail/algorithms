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
#include <thread>
#include <memory>
#include <mutex>
using namespace std;

/*
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
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
    ListNode* plusOne(ListNode* head) {
        if (!head) return nullptr;

        ListNode* prev = nullptr, *next = nullptr;
        // Reverse first
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        // Increment
        bool process = true;
        ListNode* previt = prev, *pre = nullptr;
        while (previt && process)
        {
            pre = previt;
            process = (++previt->val %= 10) == 0;
            previt = previt->next;
        }
        if (process) pre->next = new ListNode(1);

        // Reverse again
        next = nullptr, head = nullptr;
        while (prev)
        {
            next = prev->next;
            prev->next = head;
            head = prev;
            prev = next;
        }

        return head;
    }
};
void runTests()
{
    Solution s;
    ListNode* listx = new ListNode(1);
    listx->next = new ListNode(2);
    listx->next->next = new ListNode(3);
    s.plusOne(listx);

    ListNode* listy = new ListNode(9);
    listy->next = new ListNode(9);
    listy->next->next = new ListNode(9);
    s.plusOne(listy);
}

int main(int argc, char *argv[]) {

    runTests();
}