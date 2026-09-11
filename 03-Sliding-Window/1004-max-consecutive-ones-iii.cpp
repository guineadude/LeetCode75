// LeetCode 1004: Max Consecutive Ones III
#include <iostream>
#include <vector>

class Solution
{
public:
    int longestOnes(std::vector<int> &nums, int k)
    {
        auto s_p{0uz};
        auto f_p{0uz};
        int longestStreak{};
        int currentStreak{};

        while (f_p < nums.size())
        {
            if (nums[f_p] == 0)
            {
                --k;
            }

            while (k < 0)
            {
                if (nums[s_p] == 0)
                {
                    ++k;
                }

                --currentStreak;
                ++s_p;
            }
            ++currentStreak;
            if (currentStreak > longestStreak)
            {
                longestStreak = currentStreak;
            }
            ++f_p;
        }

        return longestStreak;
    }
};

int main()
{
    Solution solution{};
    std::vector<int> nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int x{solution.longestOnes(nums, 3)};
    std::cout << x << " is longest streak\n";
    return 0;
}