// LeetCode 11: Container With Most Water
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        size_t LB{0uz}, RB{height.size() - 1};
        int mostWaterStored{};

        while (LB < RB)
        {
            const int currentWaterStored{
                min(height[LB], height[RB]) * static_cast<int>(RB - LB)}; // y * x
            mostWaterStored = max(mostWaterStored, currentWaterStored);
            height[LB] > height[RB] ? --RB : ++LB;
        }

        return mostWaterStored;
    }
};

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution{}.maxArea(height) << '\n';
}