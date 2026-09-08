// LeetCode 1679: Max Number of K-Sum Pairs
using namespace std;
#include <vector>
#include <algorithm>
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