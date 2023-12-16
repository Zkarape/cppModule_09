#include "RPN.hpp"

double RPNalgo(const std::string &expression);

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw std::runtime_error("Error: ac should be 2");
        double res = RPNalgo(av[1]);
        std::cout << "Result is " << res << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}