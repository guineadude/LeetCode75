// LeetCode 649: Dota2 Senate
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        if (senate.empty())
            return "";
        int radiantCount{}, direCount{};

        for (char c : senate)
        {
            if (c == 'R')
                radiantCount++;
            else
                direCount++;
        }
        int radiantBans{}, direBans{};

        queue<char> senateQueue{senate.begin(), senate.end()};

        while (radiantCount > 0 && direCount > 0)
        {
            const char senator{senateQueue.front()};
            senateQueue.pop();

            if (senator == 'R')
            {
                if (direBans > 0)
                {
                    --direBans;
                    --radiantCount;
                }
                else
                {
                    ++radiantBans;
                    senateQueue.push('R');
                }
            }
            else if (radiantBans > 0)
            {
                --radiantBans;
                --direCount;
            }
            else
            {
                ++direBans;
                senateQueue.push('D');
            }
        }

        return (radiantCount > 0) ? string{"Radiant"} : string{"Dire"};
    }
};

int main()
{
    Solution solution;
    string senate = "RDD";
    string result = solution.predictPartyVictory(senate);
    cout << result << endl; // Output: "Dire"
    return 0;
}