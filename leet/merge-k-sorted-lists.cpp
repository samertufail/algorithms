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

/* 
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
	static bool compare(ListNode* left, ListNode* right)
	{
		return left->val < right->val;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// For each list we push the values to the priority queue which is a max heap.
		// At each push heapify puts the max element at the top.
		int len = lists.size(); if (len == 0) return NULL;
		ListNode* sortedList = NULL;
		priority_queue<ListNode*, vector<ListNode*>, decltype(&compare)> pq(&compare);
		for (int i = 0; i < len; ++i)
		{
			ListNode* head = lists[i];
			while (head) { pq.push(head); head = head->next; }
		}
		// We take the elements out of the priorty queue and add elements to the head to
		// maintain the sorted list in the ascending order.
		int qsize = pq.size();
		for (int i = 0; i < qsize; ++i)
		{
			if (!sortedList) { sortedList = new ListNode(pq.top()->val); pq.pop(); }
			else {
				ListNode* node = new ListNode(pq.top()->val); pq.pop();
				node->next = sortedList;
				sortedList = node;
			}
		}

		return sortedList;
	}
};

int main(int argc, char *argv[]) {
	//
}