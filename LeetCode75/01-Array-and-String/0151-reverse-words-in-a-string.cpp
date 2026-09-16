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
		std::size_t i{};

		auto appendWordShiftIndex = [&s, &i]()
		{
			std::string word;
			for (; i < s.size(); ++i)
			{
				if (s[i] == ' ')
				{
					break;
				}
				else
				{
					word += s[i];
				}
			}
			return word;
		};

		for (; i < s.size(); ++i)
		{
			if (s[i] != ' ')
			{
				words.push_back(appendWordShiftIndex());
			}
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