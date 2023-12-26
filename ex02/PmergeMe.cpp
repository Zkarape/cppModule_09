#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

double PmergeMe::gettime(t_timeval start)
{
	t_timeval now;

	gettimeofday(&now, NULL);
	return ((static_cast<double>((now.tv_sec - start.tv_sec) * 1000) + (static_cast<double>(now.tv_usec - start.tv_usec) / 1000)));
}

void PmergeMe::sortVector()
{
	t_timeval now;
	double start, end;
	gettimeofday(&now, NULL);
	start = gettime(now);
	merge_vec_sort(_vec);
	end = gettime(now);
	std::cout << "After: ";
	printVector();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << std::fixed << end - start << " ms\n";
}

void PmergeMe::sortDeque()
{
	t_timeval now;
	double start, end;
	gettimeofday(&now, NULL);
	start = gettime(now);
	merge_deq_sort(_deq);
	end = gettime(now);
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << std::fixed << end - start << " ms\n";
}