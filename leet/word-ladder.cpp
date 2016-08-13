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
#include <iomanip>
using namespace std;

/*

Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int n = beginWord.length();
        wordList.insert(beginWord);
        wordList.insert(endWord);
        string primary = beginWord;
        string temp = "";
        int res = 0;

        while (primary != temp && primary != endWord)
        {
            temp = primary;
            bool found = false;
            for (int i = 0; i < n && !found; ++i)
            {
                char restore = primary[i];
                if (primary[i] != endWord[i]) primary[i] = endWord[i];
                if (wordList.find(primary) != wordList.end() && primary != beginWord)
                {
                    found = true;
                    ++res;
                    wordList.erase(primary);
                }
                else primary[i] = restore;
            }

            if (!found)
            {
                for (int i = 0; i < n && !found; ++i)
                {
                    char restore = primary[i];
                    for (int j = 0; j < 26; ++j)
                    {
                        primary[i] = 'a' + j;
                        if (wordList.find(primary) != wordList.end() && primary != beginWord)
                        {
                            found = true;
                            wordList.erase(primary);
                            ++res;
                            break;
                        }
                        else primary[i] = restore;
                    }
                }
            }
        }

        return primary == endWord ? res + 1 : 0;
    }
};

void runTests()
{
    Solution s;
    unordered_set<string> d1 = { "hot","dot","son","bot","log" };
    assert(0 == s.ladderLength("hit", "cog", d1));

    unordered_set<string> d2 = { "hot","dot","dog","lot","log" };
    assert(5 == s.ladderLength("hit", "cog", d2));

    unordered_set<string> d3 = { "lest", "leet", "lose", "code", "lode", "robe", "lost" };
    assert(6 == s.ladderLength("leet", "code", d3));
}

int main(int argc, char *argv[]) {

    runTests();
}