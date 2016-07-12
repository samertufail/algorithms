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
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

1
b) d|o|g                   --> d1g

1    1  1
1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

1
1---5----0
d) l|ocalizatio|n          --> l10n

Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary.
A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
*/

class ValidWordAbbr {
public:
    map<string,int> abrs;
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary)
        {
            if (word.length() > 2)
            {
                string abr = (*word.begin() + to_string(distance(word.begin(), word.end() - 2)) + *(word.end() - 1));
                ++abrs[abr];
                ++abrs['$' + word];
            }
            else abrs[word] = 0;
        }
    }

    bool isUnique(string word) {
        int len = word.length();
        string abbr = "";
        if (len > 2) abbr = *word.begin() + to_string(distance(word.begin(), word.end() - 2)) + *(word.end() - 1);
        return abrs['$' + word] == abrs[abbr];
    }
};

void runTests()
{
    vector<string> dict = { "deer", "door", "cake", "card" };
    ValidWordAbbr vwa(dict);
    assert(false == vwa.isUnique("dear"));
    assert(true == vwa.isUnique("cart"));
    assert(false == vwa.isUnique("cane"));
    assert(true == vwa.isUnique("make"));
}

int main(int argc, char *argv[]) {

    runTests();
}