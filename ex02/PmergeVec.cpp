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
	int rangeEnd = 0;
	int indexFoundByBinary = 0;

	while (i < smSize)
	{
		++power;
		n = pow(2, power) - n;

		rangeStart = rangeEnd + n - 1;
		if (rangeStart >= smSize)
			rangeStart = smSize - 1;
		while (rangeStart >= rangeEnd)
		{
			indexFoundByBinary = binarySearch(largers, smallers[rangeStart]);
			largers.insert(largers.begin() + indexFoundByBinary, smallers[rangeStart]);
			i++;
			rangeStart--;
		}
		rangeEnd += n;
	}
}

void PmergeMe::merge_vec_sort(std::vector<int> &vec)
{
	int i = 0;
	int j = 0;
	int size = vec.size();
	std::vector<int> largers;
	std::vector<int> smallers;

	if (size == 2 || size == 3)
	{
		insertion_vector(vec);
		return;
	}
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
		largers.push_back(vec[i]);
	}
	merge_vec_sort(largers);
	insert(largers, smallers);
	vec = largers;
}