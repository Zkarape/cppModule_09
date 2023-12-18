#include "PmergeMe.hpp"

void PmergeMe::insert(std::vector<int>& x, std::vector<int> y)
{
	int n = 0;
	int power = 0;
	size_t start_index = 0;
	size_t end_index = 0;

	for (size_t i = 0; i < y.size();)
	{
		++power;
		n = pow(2, power) - n;
		start_index += n;
		end_index = start_index - n;
		if (start_index > y.size())
			start_index = y.size();
		for (size_t j = start_index - 1; j >= end_index;)
		{
			x.insert(std::upper_bound(x.begin(), x.end(), y[j]), y[j]);
			++i;
			if (j == 0)
				break ;
			--j;
		}
	}
}

void PmergeMe::merge_vec_sort()
{
	int					unpaired;
	std::vector<int>	x;
	std::vector<int>	y;
	size_t size = _vec.size() / 2 + (_vec.size() % 2);
	unpaired = ((_vec.size() % 2 == 0) ? -1 : _vec[_vec.size() - 1]);
	if (_vec.size() == 2 || _vec.size() == 3)
	{
		insertion_vector(_vec);
		return ;
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (i != size - 1 || _vec.size() % 2 == 0)
		{
			int n = _vec[i * 2], m = _vec[i * 2 + 1];
			if (n > m)
				std::swap(n, m);
			x.push_back(m);
			y.push_back(n);
		}
	}
	if (unpaired != -1)
		y.push_back(unpaired);
	merge_vec_sort();
	insert(x, y);
	_vec = x;
}