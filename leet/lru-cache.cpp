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
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 

When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

struct node
{
    int key;
    int val;
    node(int key, int val) : key(key), val(val) { };
};

class LRUCache {
private:
    typedef list<node> cache;
    int caps;
    cache cach;
    unordered_map<int, cache::iterator> map;
public:
    LRUCache(int capacity) : caps(capacity) {

    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        map[key] = update(it->second);
        return map[key]->val;
    }

    void set(int key, int value) {
        auto it = map.find(key);
        if (it != map.end())
        {
            // Update since setting a value already there is also an access.
            map[key] = update(it->second);
            map[key]->val = value;
        }
        else
        {
            if (map.size() < caps)
            {
                map[key] = cach.insert(cach.end(), node(key, value));
            }
            else
            {
                // Invalidate
                map.erase(cach.front().key);
                cach.pop_front();
                map[key] = cach.insert(cach.end(), node(key, value));
            }
        }
    }

    cache::iterator update(cache::iterator in)
    {
        cache::iterator pos = cach.insert(cach.end(), *in);
        cach.erase(in);
        return pos;
    }
};

void runTests()
{
    LRUCache cach(1);
    cach.set(2, 1);
    assert(1 == cach.get(2));
    cach.set(3, 2);
    assert(-1 == cach.get(2));
    assert(2 == cach.get(3));
}

int main(int argc, char *argv[]) {
    runTests();
}