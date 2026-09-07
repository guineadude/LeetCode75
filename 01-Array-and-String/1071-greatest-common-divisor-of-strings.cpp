// LeetCode 1071: Greatest Common Divisor of Strings
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }
        const size_t gcdSize{gcd(str1.size(), str2.size())};
        return str1.substr(0, gcdSize);
    }
};

int main()
{
    cout << Solution{}.gcdOfStrings("ABCABC", "ABC") << '\n';
}