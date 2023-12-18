#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

double PmergeMe::gettime(t_timeval start)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return ((static_cast<double>((now.tv_sec - start.tv_sec) * 1000)
		+ (static_cast<double>(now.tv_usec - start.tv_usec) / 1000)));
}

void PmergeMe::sortVector()
{
	t_timeval now;
	double start, end;
	gettimeofday(&now, NULL);
	start = gettime(now);
	merge_vec_sort();
	end = gettime(now);
	std::cout << "Time taken by std::vector: " << std::fixed << end - start << " ms\n\n";
	std::cout << "std::vector after sorting: ";
    printVector();
}

void PmergeMe::sortDeque()
{
	t_timeval now;
	double start, end;
	gettimeofday(&now, NULL);
	start = gettime(now);
	merge_deque_sort();
	end = gettime(now);
	std::cout << "Time taken by std::deque: " << std::fixed << end - start << " ms\n\n";
	std::cout << "std::deque after sorting: ";
    printDeque();
}