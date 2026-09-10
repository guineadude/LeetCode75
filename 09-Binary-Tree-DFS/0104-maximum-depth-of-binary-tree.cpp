#include <iostream>
#include <vector>

class Solution
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int sum{};
        int shortest_length{};
        std::size_t window_start{};
        std::size_t window_end{};

        while (window_end < nums.size())
        {
            sum += nums[window_end];

            while (sum >= target) // Shrink the window from the start
            {
                const int current_length{
                    static_cast<int>(window_end - window_start + 1)};

                if (current_length < shortest_length || shortest_length == 0)
                {
                    shortest_length = current_length;
                }

                sum -= nums[window_start];
                ++window_start;
            }

            ++window_end;
        }

        return shortest_length;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int target = 11;
    int result = solution.minSubArrayLen(target, nums);
    std::cout << "Shortest subarray length: " << result << std::endl;
}