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
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

*/

class Stack {
private:
    queue<int> qMain;
public:
    // Push element x onto stack.
    void push(int x) {
        qMain.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> qBackup;
        while (qMain.size() != 1)
        {
            qBackup.push(qMain.front());
            qMain.pop();
        }
        qMain = qBackup;
    }

    // Get the top element.
    int top() {
        queue<int> qBackup;
        while (qMain.size() != 1)
        {
            qBackup.push(qMain.front());
            qMain.pop();
        }

        int retVal = qMain.front();
        qBackup.push(retVal);
        qMain = qBackup;
 
        return retVal;
    }

    // Return whether the stack is empty.
    bool empty() {
        return qMain.empty();
    }
};

void runTests()
{
    Stack st;
    st.push(1); st.push(2); st.push(3);
    assert(3 == st.top());
    
    st.pop();
    assert(2 == st.top());
    
    st.pop();
    assert(1 == st.top());
}

int main(int argc, char *argv[]) {
    runTests();
}