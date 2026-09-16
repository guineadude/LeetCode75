// LeetCode 20: Valid Parentheses
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> stack;
        for (const char character : s)
        {
            if (character == '(' || character == '{' || character == '[')
            {
                stack.push_back(character);
                continue;
            }
            if (stack.empty())
            {
                return false;
            }

            const char top{stack.back()};
            if ((top == '(' && character == ')') ||
                (top == '{' && character == '}') ||
                (top == '[' && character == ']'))
            {
                stack.pop_back();
            }
            else
            {
                return false;
            }
        }
        return stack.empty();
    }
};

int main()
{
    cout << boolalpha << Solution{}.isValid("()[]{}") << '\n';
}