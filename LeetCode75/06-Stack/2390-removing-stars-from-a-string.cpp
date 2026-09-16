// LeetCode 2390: Removing Stars From a String
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        vector<char> chars{};
        chars.reserve(s.size());

        for (char c : s)
        {
            if (c == '*')
            {
                if (!chars.empty())
                {
                    chars.pop_back();
                }
            }
            else
            {
                chars.emplace_back(c);
            }
        }
        string rS{};
        rS.reserve(chars.size());
        for (char c : chars)
        {
            rS.push_back(c);
        }

        return rS;
    }
};

int main()
{
    std::cout << Solution{}.removeStars("leet**cod*e") << '\n';
}