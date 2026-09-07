// LeetCode 374: Guess Number Higher or Lower
#include <iostream>

using namespace std;

int pick{};

int guess(int number)
{
    return (number > pick) ? -1 : (number < pick) ? 1
                                                  : 0;
}

class Solution
{
public:
    int guessNumber(int n)
    {
        int lower{1};
        int upper{n};
        while (lower <= upper)
        {
            const int middle{lower + (upper - lower) / 2};
            switch (guess(middle))
            {
            case 0:
                return middle;
            case 1:
                lower = middle + 1;
                break;
            default:
                upper = middle - 1;
                break;
            }
        }
        return -1;
    }
};

int main()
{
    pick = 6;
    cout << Solution{}.guessNumber(10) << '\n';
}