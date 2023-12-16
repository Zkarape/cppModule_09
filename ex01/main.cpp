#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (!IsValidStr(av[1], "\t */+-1234567890"))
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