// LeetCode 1456: Maximum Number of Vowels in a Substring of Given Length
#include <string>
using namespace std;
#include <iostream>
class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k)
    {
        int LB = 0;
        int RB = 0;
        int maxVowelsFound = 0;

        for (; RB < k; ++RB)
        {
            if (isVowel(s[RB]))
                ++maxVowelsFound;
        }

        int currentVowels = maxVowelsFound;

        if (currentVowels == k)
            return k;

        const int size = s.size();

        while (RB < size)
        {
            if (isVowel(s[LB]))
                --currentVowels;

            if (isVowel(s[RB]))
                ++currentVowels;

            ++LB;
            ++RB;

            maxVowelsFound = max(maxVowelsFound, currentVowels);
        }

        return maxVowelsFound;
    }
};