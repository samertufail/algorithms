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
The read function may be called multiple times.    */

class Solution {
private:
    int available = 0, curp = 0;
    char store[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
       	if (n <= 0) return n; int i = 0;
    	while (available > 0 && i < n) {
    		buf[i++] = store[curp++%4]; --available;
    	}
    	int bytes = 0;
    	while (true)
    	{
    		if (i >= n) return i;
    		bytes = read4(store);
    		if (bytes == 0) return i;
    		while (bytes && i < n) {
    			buf[i++] = store[curp++%4]; --bytes;
    		}
    		available = bytes;
    	}
    }
};

int main(int argc, char *argv[]) {
	
}