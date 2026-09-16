// LeetCode 1431: Kids With the Greatest Number of Candies
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        const int largestNumber{*max_element(candies.begin(), candies.end())};
        vector<bool> canHaveMostCandies;
        canHaveMostCandies.reserve(candies.size());

        for (const int candyCount : candies)
        {
            canHaveMostCandies.push_back(candyCount + extraCandies >= largestNumber);
        }
        return canHaveMostCandies;
    }
};

int main()
{
    vector<int> candies{2, 3, 5, 1, 3};
    for (const bool canHaveMost : Solution{}.kidsWithCandies(candies, 3))
    {
        cout << boolalpha << canHaveMost << ' ';
    }
    cout << '\n';
}