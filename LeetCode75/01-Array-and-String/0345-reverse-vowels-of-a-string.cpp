// LeetCode 345: Reverse Vowels of a String
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        if (s.empty())
        {
            return s;
        }

        const string vowels{"aeiouAEIOU"};
        size_t left{};
        size_t right{s.length() - 1};

        while (left < right)
        {
            while (left < right && vowels.find(s[left]) == string::npos)
            {
                ++left;
            }
            while (left < right && vowels.find(s[right]) == string::npos)
            {
                --right;
            }
            if (left < right)
            {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};

int main()
{
    cout << Solution{}.reverseVowels("hello") << '\n';
}