// LeetCode 1207: Unique Number of Occurrences
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> frequencyMap;
        for (const int number : arr)
        {
            ++frequencyMap[number];
        }

        unordered_set<int> seenFrequencies;
        seenFrequencies.reserve(frequencyMap.size());
        for (const auto &[number, frequency] : frequencyMap)
        {
            if (seenFrequencies.contains(frequency))
            {
                return false;
            }
            seenFrequencies.emplace(frequency);
        }
        return true;
    }
};

int main()
{
    vector<int> arr{1, 2, 2, 1, 1, 3};
    cout << boolalpha << Solution{}.uniqueOccurrences(arr) << '\n';
}