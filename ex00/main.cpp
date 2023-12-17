#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2 || !av[1])
            throw(std::runtime_error("Invalid arguments"));
        BitcoinExchange instance(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}