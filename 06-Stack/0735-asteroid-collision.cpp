// LeetCode 735: Asteroid Collision

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class Solution
{
public:
    std::vector<int> asteroidCollision(std::vector<int> &asteroids)
    {
        std::stack<int> asteroidStack;

        for (const auto asteroid : asteroids)
        {
            if (asteroidStack.empty())
            {
                asteroidStack.push(asteroid);
                continue;
            }
            if (asteroid < 0)
            {
                bool destroyed = false;
                while (!asteroidStack.empty() && asteroidStack.top() > 0)
                {
                    if (asteroidStack.top() < std::abs(asteroid))
                    {
                        asteroidStack.pop();
                    }
                    else if (asteroidStack.top() > std::abs(asteroid))
                    {
                        destroyed = true;
                        break;
                    }
                    else
                    {
                        asteroidStack.pop();
                        destroyed = true;
                        break;
                    }
                }

                if (!destroyed)
                {
                    asteroidStack.push(asteroid);
                }
                continue;
            }
            asteroidStack.push(asteroid);
        }

        std::vector<int> result;

        while (!asteroidStack.empty())
        {
            result.push_back(asteroidStack.top());
            asteroidStack.pop();
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> asteroids = {3, 5, -6, 2, -1, 4};
    std::vector<int> result = solution.asteroidCollision(asteroids);
    for (int asteroid : result)
    {
        std::cout << asteroid << " ";
    }
    std::cout << std::endl;
}