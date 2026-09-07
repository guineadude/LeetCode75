// LeetCode 643: Maximum Average Subarray I
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int highestSum{};
        for (int index{}; index < k; ++index)
        {
            highestSum += nums[index];
        }

        int currentSum{highestSum};
        for (size_t right{static_cast<size_t>(k)}; right < nums.size(); ++right)
        {
            currentSum += nums[right] - nums[right - k];
            if (currentSum > highestSum)
            {
                highestSum = currentSum;
            }
        }
        return static_cast<double>(highestSum) / k;
    }
};

int main()
{
    vector<int> nums{1, 12, -5, -6, 50, 3};
    cout << Solution{}.findMaxAverage(nums, 4) << '\n';
}