// LeetCode 334: Increasing Triplet Subsequence
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int first{INT_MAX};
        int second{INT_MAX};
        for (const int number : nums)
        {
            if (number <= first)
            {
                first = number;
            }
            else if (number <= second)
            {
                second = number;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    cout << boolalpha << Solution{}.increasingTriplet(nums) << '\n';
}