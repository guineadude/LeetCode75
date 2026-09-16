// LeetCode 1657: Determine if Two Strings Are Close

#include <string>
#include <array>
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    array<int, 26> freq1{};
    array<int, 26> freq2{};

    bool closeStrings(string word1, string word2)
    {
        if (!(word1.length() == word2.length()))
            return false;

        for (char c : word1)
        {
            ++freq1[c - 'a'];
        }
        for (char c : word2)
        {
            ++freq2[c - 'a'];
        }

        for (int i = 0; i < 26; ++i)
        {
            if ((freq1[i] == 0) != (freq2[i] == 0))
                return false;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};