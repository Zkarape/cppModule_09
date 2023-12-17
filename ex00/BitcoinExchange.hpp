#ifndef BE_HPP
#define BE_HPP

#include <iostream>
#include <map>

struct for_date_check
{
    std::string year;
    std::string month;
    std::string day;
};

class BitcoinExchange
{
private:
    std::map<std::string, double> _map;
    std::string _data;
    // char **_keys;
public:
    BitcoinExchange();
    bool checkDate(const for_date_check &str);
    ~BitcoinExchange();
    void openFile(const std::string &arg);
    bool parseData();
    void fillMap();
};

#endif