// LeetCode 1768: Merge Strings Alternately
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result;
        result.reserve(word1.size() + word2.size());
        for (size_t index{}; index < word1.size() || index < word2.size(); ++index)
        {
            if (index < word1.size())
            {
                result.push_back(word1[index]);
            }
            if (index < word2.size())
            {
                result.push_back(word2[index]);
            }
        }
        return result;
    }
};

int main()
{
    cout << Solution{}.mergeAlternately("abc", "pqr") << '\n';
}