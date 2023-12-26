#include "PmergeMe.hpp"

void PmergeMe::printVector() {
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque() {
    for (std::deque<int>::const_iterator it = _deq.begin(); it != _deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
