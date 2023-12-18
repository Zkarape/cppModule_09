#ifndef BE_HAPPY
#define BE_HAPPY

#include <cassert>
#include <cmath>
#include <vector>
#include <iostream>
#include <limits>
#include <sstream>
#include <stack>
#include <string>
#include <cfloat>
#include <sys/time.h>

typedef struct timeval t_timeval;

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

public:
    PmergeMe();
    ~PmergeMe();
    void insert(std::vector<int> &x, std::vector<int> y);
    void insert(std::deque<int> &x, std::deque<int> y);
    double gettime(t_timeval start);
    void argv_check_cont_fill(char **argv);
    int strtoint(char *str);
    void fillVector(int n);
    void fillDeque(int m);
    void printVector();
    void printDeque();
    void merge_vec_sort();
    void merge_deque_sort();
    void sortVector();
    void sortDeque();
    void insertion_vector(std::vector<int> &nums);
    void insertion_deque(std::deque<int> &nums);
};

#endif