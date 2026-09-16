// LeetCode 283: Move Zeroes
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        size_t left{};
        for (size_t right{}; right < nums.size(); ++right)
        {
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                ++left;
            }
        }
    }
};

int main()
{
    vector<int> nums{0, 1, 0, 3, 12};
    Solution{}.moveZeroes(nums);
    for (const int number : nums)
    {
        cout << number << ' ';
    }
    cout << '\n';
}