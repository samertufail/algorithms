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
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

class TrieNode {
public:
    bool wordEnd;
    unordered_map<char, TrieNode*> map;
    // Initialize your data structure here.
    TrieNode() : wordEnd(false) {
		/* Pre initialize nodes, we can omit this step or not since map will add the value if it doesnt find it.
		   Good for a start point though. 
		*/
		
        //for (char c = 'a'; c <= 'z'; ++c) map[c] = nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int len = word.length();
        if (len > 0)
        {
            TrieNode* node = root;
            for (int i = 0; i < len; ++i)
            {
                if (node->map[word[i]])
                {
                    node = node->map[word[i]];
                }
                else
                {
                    node->map[word[i]] = new TrieNode();
                    node = node->map[word[i]];
                }
            }
            node->wordEnd = true;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int len = word.length();
        if (len > 0)
        {
            TrieNode* node = root;
            for (int i = 0; i < len; ++i)
            {
                if (node->map[word[i]])
                {
                    node = node->map[word[i]];
                }
                else return false;
            }
            return node->wordEnd;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len = prefix.length();
        if (len > 0)
        {
            TrieNode* node = root;
            for (int i = 0; i < len; ++i)
            {
                if (node->map[prefix[i]]) node = node->map[prefix[i]];
                else return false;
            }
            return true;
        }
        return false;
    }

private:
    TrieNode* root;
};

void runTests()
{
     Trie trie;
     trie.insert("somestring");
     trie.insert("som");
     trie.insert("test");
     trie.insert("zaki");
     assert(true == trie.search("som"));
     assert(true == trie.search("somestring"));
     assert(true == trie.search("test"));
     assert(false == trie.search("tes"));
     assert(true == trie.startsWith("test"));
     assert(true == trie.startsWith("so"));
     assert(true == trie.startsWith("s"));
     assert(false == trie.startsWith("zeb"));
     assert(false == trie.startsWith("zakia"));
}

int main(int argc, char *argv[]) {
    runTests();
}