#include "PmergeMe.hpp"

void PmergeMe::fillVector(int n)
{
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
    {
        *it = n;
        std::cout << "number == " << *it << std::endl;
    }
}

void PmergeMe::fillDeque(int n)
{
    for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it)
    {
        *it = n;
    }
}

int PmergeMe::strtoint(char *str)
{
    char *ptr;
    long number = strtol(str, &ptr, 10);
    if (*ptr != '\0' || number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
    {
        // std::cout << "number == " << *ptr << std::endl;
        throw(std::logic_error("Error: string is invalid or out of range"));
    }
    return (number);
}

void PmergeMe::argv_check_cont_fill(char **argv)
{
    for (size_t i = 1; argv[i]; ++i)
    {
        for (size_t j = 0; argv[i][j]; ++j)
        {
            if (argv[i][j] != ' ' && argv[i][j] != '\t' && (argv[i][j] < 48 || argv[i][j] > 57))
                throw(std::logic_error("Error: nondigits detected"));
        }
        try
        {
            _vec.push_back(strtoint(argv[i]));
            // fillVector(strtoint(argv[i]));
            // fillDeque(strtoint(argv[i]));
        }
        catch (std::exception &obj)
        {
            std::cerr << "Error: " << obj.what() << '\n';
            exit(1);
        }
    }
}

int main(int argc, char **argv)
{
    // if (argc < 2)
    //     return (0);
    try
    {
        PmergeMe merge;
        merge.argv_check_cont_fill(argv);
        std::cout << "Before: ";
        merge.printVector();
        merge.sortVector();
        // merge.sortDeque();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}