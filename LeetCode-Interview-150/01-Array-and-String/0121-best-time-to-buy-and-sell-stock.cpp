#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int profitRecord{};
        int smallestPrice{prices[0]};

        for (const auto price : prices)
        {
            int currentPrice{price};

            if (currentPrice < smallestPrice)
            {
                smallestPrice = currentPrice;
            }

            if (currentPrice - smallestPrice > profitRecord)
            {
                profitRecord = currentPrice - smallestPrice;
            }
        }
        return profitRecord;
    }
};

int main()
{
    Solution solution;
    std::vector<int> prices{7, 6, 4, 3, 1};
    int maxProfit = solution.maxProfit(prices);
    std::cout << "Max Profit: " << maxProfit << std::endl;
}