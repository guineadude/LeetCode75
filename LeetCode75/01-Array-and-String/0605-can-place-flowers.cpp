// LeetCode 605: Can Place Flowers
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int flowersPlanted{};
        for (size_t index{}; index < flowerbed.size(); ++index)
        {
            const bool empty{flowerbed[index] == 0};
            const bool leftEmpty{index == 0 || flowerbed[index - 1] == 0};
            const bool rightEmpty{index == flowerbed.size() - 1 || flowerbed[index + 1] == 0};

            if (empty && leftEmpty && rightEmpty)
            {
                flowerbed[index] = 1;
                ++flowersPlanted;
            }
        }
        return flowersPlanted >= n;
    }
};

int main()
{
    vector<int> flowerbed{1, 0, 0, 0, 1};
    cout << boolalpha << Solution{}.canPlaceFlowers(flowerbed, 1) << '\n';
}