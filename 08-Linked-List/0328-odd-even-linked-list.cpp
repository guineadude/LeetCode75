// LeetCode 328: Odd Even Linked List

#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
    int compress(std::vector<char> &chars)
    {
        int slow{0};
        int fast{0};
        int write{0};

        while (fast < chars.size())
        {
            while (fast < chars.size() && chars[fast] == chars[slow])
            {
                ++fast;
            }

            int repetitions{fast - slow};

            chars[write++] = chars[slow];

            if (repetitions > 1)
            {
                std::string count{std::to_string(repetitions)};

                for (char c : count)
                {
                    chars[write++] = c;
                }
            }

            slow = fast;
        }

        chars.resize(write);
        return write;
    }
};

int main()
{
    Solution solution;
    std::vector<char> chars{'a'};
    int x = solution.compress(chars);
    for (char c : chars)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cout << x << std::endl;
    return 0;
}