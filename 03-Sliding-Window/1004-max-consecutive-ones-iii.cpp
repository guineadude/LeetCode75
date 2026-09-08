// LeetCode 1004: Max Consecutive Ones III
using namespace std;
#include <iostream>
#include <vector>

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        size_t lp{0uz}, rp{nums.size() - 1};
        int nOOperations{};
        sort(nums.begin(), nums.end());

        while (lp < rp)
        {
            const int sum{nums[lp] + nums[rp]};
            if (sum == k)
            {
                ++nOOperations;
                ++lp;
                --rp;
            }
            else if (sum < k)
            {
                ++lp;
            }
            else
            {
                --rp;
            }
        }

        return nOOperations;
    }
};