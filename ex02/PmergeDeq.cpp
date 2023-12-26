#include "PmergeMe.hpp"

size_t binarySearchdeque(const std::deque<int> &sorteddeque, int number)
{
	size_t low = 0;
	size_t high = sorteddeque.size();

	while (low < high)
	{
		size_t mid = low + (high - low) / 2;

		if (sorteddeque[mid] <= number)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::insert(std::deque<int> &largers, std::deque<int> &smallers)
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
			indexFoundByBinary = binarySearchdeque(largers, smallers[rangeStart]);
			largers.insert(largers.begin() + indexFoundByBinary, smallers[rangeStart]);
			i++;
			rangeStart--;
		}
		rangeEnd += n;
	}
}

void PmergeMe::merge_deq_sort(std::deque<int> &deq)
{
	int i = 0;
	int j = 0;
	int size = deq.size();
	std::deque<int> largers;
	std::deque<int> smallers;

	if (size == 2 || size == 3)
	{
		insertion_deque(deq);
		return ;
	}
	while (i + 1 < size)
	{
		if (deq[i] > deq[i + 1])
		{
			largers.push_back(deq[i]);
			smallers.push_back(deq[i + 1]);
		}
		else
		{
			largers.push_back(deq[i + 1]);
			smallers.push_back(deq[i]);
		}
		i += 2;
	}
	if (i < size)
	{
		largers.push_back(deq[i]);
	}
	merge_deq_sort(largers);
	insert(largers, smallers);
	deq = largers;
}