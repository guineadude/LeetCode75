// LeetCode 2352: Equal Row and Column Pairs
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        unordered_map<string, int> rows;
        unordered_map<string, int> columns;

        for (auto row{0uz}; row < grid.size(); ++row)
        {
            string rowKey;

            for (auto column{0uz}; column < grid.size(); ++column)
            {
                rowKey += to_string(grid[row][column]) + ",";
            }

            rows[rowKey]++;
        }

        for (auto column{0uz}; column < grid.size(); ++column)
        {
            string columnKey;

            for (auto row{0uz}; row < grid.size(); ++row)
            {
                columnKey += to_string(grid[row][column]) + ",";
            }

            columns[columnKey]++;
        }

        int numPairs{};

        for (const auto &[key, count] : rows)
        {
            numPairs += count * columns[key];
        }

        return numPairs;
    }
};

int main()
{
    vector<vector<int>> grid{{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    cout << Solution{}.equalPairs(grid) << '\n';
}