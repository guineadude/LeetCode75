// LeetCode 1071: Greatest Common Divisor of Strings
#include <iostream>
#include <numeric>
#include <string>

class Solution
{
public:
    std::string gcdOfStrings(std::string str1, std::string str2)
    {
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }
        const size_t gcdSize{std::gcd(str1.size(), str2.size())};
        return str1.substr(0, gcdSize);
    }
};

int main()
{
    std::cout << Solution{}.gcdOfStrings("ABCABC", "ABC") << '\n';
}