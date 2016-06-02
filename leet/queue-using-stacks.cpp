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
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

*/

class Queue {
private:
    stack<int> st;
public:
    // Push element x to the back of queue.
    void push(int x) {
        st.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        int data = 0;
        if (st.size() == 1)
        {
            st.pop();
            return;
        }
        else
        {
            data = st.top();
            st.pop();
            pop();
            st.push(data);
        }
    }

    // Get the front element.
    int peek(void) {
        int retVal = 0, data = 0;
        if (st.size() == 1)
        {
            return st.top();
        }
        else {
            data = st.top();
            st.pop();
            retVal = peek();
            st.push(data);
        }

        return retVal;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};

void runTests()
{
    Queue q;
    q.push(1); q.push(2); q.push(3);
    assert(1 == q.peek());
    
    q.pop();
    assert(2 == q.peek());
    
    q.pop();
    assert(3 == q.peek());
}

int main(int argc, char *argv[]) {
    runTests();
}