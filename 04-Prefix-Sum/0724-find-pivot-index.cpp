// LeetCode 724: Find Pivot Index
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int leftSum{};
        int rightSum{};
        for (const int number : nums)
        {
            rightSum += number;
        }

        for (size_t index{}; index < nums.size(); ++index)
        {
            rightSum -= nums[index];
            if (leftSum == rightSum)
            {
                return static_cast<int>(index);
            }
            leftSum += nums[index];
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{1, 7, 3, 6, 5, 6};
    cout << Solution{}.pivotIndex(nums) << '\n';
}