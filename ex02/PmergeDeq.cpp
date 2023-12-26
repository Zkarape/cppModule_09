#include "PmergeMe.hpp"

size_t binarySearch(const std::deque<int> &sorteddeque, int number)
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

		for (rangeStart = rangeEnd + n - 1; rangeStart >= rangeEn; rangeStart--)
		{
			if (rangeStart >= 0 && rangeStart < smSize)
			{
				indexFoundByBinary = binarySearch(largers, smallers[rangeStart]);
				if (indexFoundByBinary >= 0 && static_cast<size_t>(indexFoundByBinary) <= largers.size())
				{
					largers.insert(largers.begin() + indexFoundByBinary, smallers[rangeStart]);
					i++;
				}
				else
					std::cerr << "Error: Invalid index found by binarySearch in PmergeMe::insert." << std::endl;
			}
			else
			{
				std::cout << "rangeStart == " << rangeStart << "smSize == " << smSize << std::endl;
				std::cerr << "Error: Invalid rangeStart in PmergeMe::insert." << std::endl;
			}
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
		return;
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