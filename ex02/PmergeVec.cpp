#include "PmergeMe.hpp"

size_t binarySearch(const std::vector<int> &sortedVector, int number)
{
	size_t low = 0;
	size_t high = sortedVector.size();

	while (low < high)
	{
		size_t mid = low + (high - low) / 2;

		if (sortedVector[mid] <= number)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::insert(std::vector<int> &largers, std::vector<int> &smallers)
{
	int power = 0;
	int n = 0;
	int i = 0;
	int smSize = smallers.size();
	int rangeStart = 0;
	int rangeEnd = -2;
	int indexFoundByBinary = 0;

	// for (std::vector<int>::const_iterator it = smallers.begin(); it != smallers.end(); ++it)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	// if (static_cast<size_t>(smSize) == _vec.size() / 2)
	// {
	// 	largers.insert(largers.begin(), smallers[0]);
	// 	return ;
	// }
	while (i < smSize)
	{
		++power;
		n = pow(2, power) - n;
		rangeEnd += n;
		rangeStart = rangeEnd + n - 1;
		if (rangeEnd > smSize)
			rangeEnd -= n;
		if (rangeStart > smSize)
			rangeStart = smSize - 1;
		if (rangeStart == 0)
			std::cout << "added" << std::endl;
		while (rangeStart >= rangeEnd)
		{
			indexFoundByBinary = binarySearch(largers, smallers[rangeStart]);
			largers.insert(largers.begin() + indexFoundByBinary, smallers[rangeStart]);
			i++;
			rangeStart--;
		}
	}
}

void PmergeMe::merge_vec_sort(std::vector<int> &vec)
{
	int i = 0;
	int size = vec.size();
	std::vector<int> largers;
	std::vector<int> smallers;

	if (size == 0 || size == 1)
		return;
	while (i + 1 < size)
	{
		if (vec[i] > vec[i + 1])
		{
			largers.push_back(vec[i]);
			smallers.push_back(vec[i + 1]);
		}
		else
		{
			largers.push_back(vec[i + 1]);
			smallers.push_back(vec[i]);
		}
		i += 2;
	}
	if (i < size)
	{
		smallers.push_back(vec[i]);
	}
	merge_vec_sort(largers);
	insert(largers, smallers);
	if (vec.size() == largers.size())
		vec = largers;
}