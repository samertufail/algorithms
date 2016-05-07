#include "stdafx.h"
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
 The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Note:
The read function will only be called once for each test case. */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
    	if (n <= 0) return n;
    	int bytes = 0, totalBytes = 0;
    	while (true) {
    		bytes = read4(buf + totalBytes);
    		totalBytes += bytes;
    		if (bytes == 0) return totalBytes;
    		if (totalBytes >= n) return n;
    	}
    }
};

int main(int argc, char *argv[]) {
	
}