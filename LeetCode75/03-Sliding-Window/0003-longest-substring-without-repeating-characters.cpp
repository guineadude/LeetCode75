// LeetCode 3: Longest Substring Without Repeating Characters
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> characters;
        size_t left{};
        size_t longest{};
        for (size_t right{}; right < s.size(); ++right)
        {
            while (characters.contains(s[right]))
            {
                characters.erase(s[left++]);
            }
            characters.insert(s[right]);
            longest = max(longest, right - left + 1);
        }
        return static_cast<int>(longest);
    }
};

int main()
{
    cout << Solution{}.lengthOfLongestSubstring("abcabcbb") << '\n';
}