#include "PmergeMe.hpp"

void PmergeMe::insertion_vector(std::vector<int>& nums)
{
	for (size_t i = 1; i < nums.size(); ++i)
	{
		int j = i;
		while (j > 0 && nums[j] < nums[j - 1])
		{
			std::swap(nums[j], nums[j - 1]);
			j--;
		}
	}
}


void PmergeMe::insertion_deque(std::deque<int>& nums)
{
	for (size_t i = 1; i < nums.size(); ++i)
	{
		int j = i;
		while (j > 0 && nums[j] < nums[j - 1])
		{
			std::swap(nums[j], nums[j - 1]);
			j--;
		}
	}
}

