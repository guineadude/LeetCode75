// LeetCode 933: Number of Recent Calls
#include <iostream>
#include <queue>
using namespace std;

class RecentCounter
{
public:
    queue<int> timeStamps;

    RecentCounter()
    {
    }

    int ping(int t)
    {
        timeStamps.push(t);

        while (t - timeStamps.front() > 3000)
        {
            timeStamps.pop();
        }

        return std::ssize(timeStamps);
    }
};

int main()
{
    RecentCounter *obj = new RecentCounter();
    cout << obj->ping(1) << endl;    // Output: 0
    cout << obj->ping(100) << endl;  // Output: 1
    cout << obj->ping(3001) << endl; // Output: 2
    cout << obj->ping(3002) << endl; // Output: 3
    return 0;
}