// LeetCode 392: Is Subsequence
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        size_t sIndex{};
        for (const char character : t)
        {
            if (sIndex < s.size() && character == s[sIndex])
            {
                ++sIndex;
            }
        }
        return sIndex == s.size();
    }
};

int main()
{
    cout << boolalpha << Solution{}.isSubsequence("abc", "ahbgdc") << '\n';
}