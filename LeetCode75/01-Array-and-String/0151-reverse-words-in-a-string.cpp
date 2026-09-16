// LeetCode 151: Reverse Words in a String

#include <iostream>
#include <ranges>
#include <string>
#include <vector>

class Solution
{
public:
	std::string reverseWords(std::string s)
	{
		std::vector<std::string> words;

		for (std::size_t i{}; i < s.size();)
		{
			if (s[i] == ' ')
			{
				++i;
				continue;
			}

			const std::size_t start{i};
			for (; i < s.size() && s[i] != ' '; ++i)
			{
			}

			words.push_back(s.substr(start, i - start));
		}

		std::string result;

		for (std::string &word : std::views::reverse(words))
		{
			if (!result.empty())
			{
				result += ' ';
			}
			result += word;
		}

		return result;
	}
};

int main()
{
	Solution solution;
	std::string s = "a good   example";
	std::string result = solution.reverseWords(s);
	std::cout << result << std::endl;
	return 0;
}