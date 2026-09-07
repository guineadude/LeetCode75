// LeetCode 2215: Find the Difference of Two Arrays
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1{nums1.begin(), nums1.end()};
        unordered_set<int> set2{nums2.begin(), nums2.end()};
        vector<int> diff1;
        vector<int> diff2;

        for (const int value : set1)
        {
            if (!set2.contains(value))
            {
                diff1.push_back(value);
            }
        }
        for (const int value : set2)
        {
            if (!set1.contains(value))
            {
                diff2.push_back(value);
            }
        }
        return {diff1, diff2};
    }
};

int main()
{
    vector<int> nums1{1, 2, 3};
    vector<int> nums2{2, 4, 6};
    for (const auto &difference : Solution{}.findDifference(nums1, nums2))
    {
        for (const int value : difference)
        {
            cout << value << ' ';
        }
        cout << '\n';
    }
}