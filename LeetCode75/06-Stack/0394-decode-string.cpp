// LeetCode 394: Decode String#include <iostream>
using namespace std;
#include <stack>
#include <string>

class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<int, string>> stack;

        string current;
        int number{};

        for (char c : s)
        {
            if (isdigit(c))
            {
                number = number * 10 + (c - '0');
            }
            else if (c == '[')
            {
                stack.push({number, current});

                number = 0;
                current.clear();
            }
            else if (c == ']')
            {
                auto [repetitions, previous] = stack.top();
                stack.pop();

                string repeated;

                for (int i{}; i < repetitions; ++i)
                {
                    repeated += current;
                }

                current = previous + repeated;
            }
            else
            {
                current += c;
            }
        }

        return current;
    }
};

int main()
{
    Solution solution;
    string s = "3[a2[c]]";
    cout << solution.decodeString(s) << endl;
    return 0;
}