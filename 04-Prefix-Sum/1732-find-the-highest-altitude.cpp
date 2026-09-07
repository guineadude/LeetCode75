// LeetCode 1732: Find the Highest Altitude
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int highestNetGain{};
        int currentHeight{};
        for (const int heightChange : gain)
        {
            currentHeight += heightChange;
            if (currentHeight > highestNetGain)
            {
                highestNetGain = currentHeight;
            }
        }
        return highestNetGain;
    }
};

int main()
{
    vector<int> gain{-5, 1, 5, 0, -7};
    cout << Solution{}.largestAltitude(gain) << '\n';
}