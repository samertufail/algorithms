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
Design a logger system that receive stream of messages along with its timestamps, each message should be printed 
if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), 
return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.
*/

class Logger {
private: 
    unordered_map<string, int> freqmsgs;
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
    If this method returns false, the message will not be printed.
    The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (freqmsgs.find(message) == freqmsgs.end()) {
            freqmsgs[message] = timestamp;
            return true;
        }
        else
        {
            if (abs(freqmsgs[message] - timestamp) < 10) return false;
            else freqmsgs[message] = timestamp;
        }
        return true;
    }
};

/**
* Your Logger object will be instantiated and called as such:
* Logger obj = new Logger();
* bool param_1 = obj.shouldPrintMessage(timestamp,message);
*/

void runTests()
{
    Logger logger;

    // logging string "foo" at timestamp 1
    assert(true == logger.shouldPrintMessage(1, "foo"));

    // logging string "bar" at timestamp 2
    assert(true == logger.shouldPrintMessage(2, "bar"));

    // logging string "foo" at timestamp 3
    assert(false == logger.shouldPrintMessage(3, "foo"));

    // logging string "bar" at timestamp 8
    assert(false == logger.shouldPrintMessage(8, "bar"));

    // logging string "foo" at timestamp 10
    assert(false == logger.shouldPrintMessage(10, "foo"));

    // logging string "foo" at timestamp 11
    assert(true == logger.shouldPrintMessage(11, "foo"));
}

int main(int argc, char *argv[]) {

    runTests();
}