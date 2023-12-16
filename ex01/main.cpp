#include "RPN.hpp"

double RPNalgo(const std::string &expression);

int main(int ac, char **av)
{
    try
    {
        if (RPNalgo(av[1]))
        {
            std::cerr << "The given string is wrong: e.i. it contains char that is not from \"\t */+-1234567890\"" << std::endl;
            return (0);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}