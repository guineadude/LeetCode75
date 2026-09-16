// LeetCode 206: Reverse Linked List
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer(nums.size());

        int cumulativeProd{1};

        // L -> R
        for (auto i{0uz}; i < nums.size(); ++i)
        {
            answer[i] = cumulativeProd;
            cumulativeProd *= nums[i];
        }

        cumulativeProd = 1;

        // R -> L
        for (auto j{std::ssize(nums) - 1}; j >= 0; --j)
        {
            answer[j] *= cumulativeProd;
            cumulativeProd *= nums[j];
        }

        return answer;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4};
    solution.productExceptSelf(nums);
    return 0;
}
