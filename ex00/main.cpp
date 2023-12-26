#include "BitcoinExchange.hpp"


//1.piti spacenery karda u ancni 
//2.data.csv-n chi kardum 

//3.2011-05-00 | 2 chpiti ashxati
//4.2011-05-a1 | 2 chpiti ashxati






int main(int ac, char **av)
{
    try
    {
        if (ac != 2 || !av[1])
            throw(std::runtime_error("Invalid arguments"));
        BitcoinExchange instance(av[1]);
        instance.fillMap();
        instance.inputParse();
        // instance.printMap();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}