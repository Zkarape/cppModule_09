#include "BitcoinExchange.hpp"
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::openFile(const std::string &arg)
{
    std::ifstream ifs(arg);
    if (ifs.is_open())
        ifs.close();
    else
        throw(std::runtime_error("Bad file input"));
    ifs >> _data;
}

bool is_only_digit(const std::string &str)
{
    int i = -1;
    int len = str.size();
    while (++i < len)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool is_leap_year(int yearInt)
{
    if ((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0)
        return (1);
    return (0);
}

bool checkDay(const for_date_check &date)
{
    char *ptr;

    int dayInt = strtol(date.day.c_str(), &ptr, 10);
    int monthInt = strtol(date.month.c_str(), &ptr, 10);
    if (monthInt <= 7 && ((monthInt % 2 == 0 && dayInt > 30) || (monthInt % 2 && dayInt > 31)))
        return (0);
    if (monthInt == 2 && ((!is_leap_year(strtol(date.year.c_str(), &ptr, 10)) && dayInt > 28) || (dayInt > 29)))
        return (0);
    if (monthInt > 7 && ((monthInt % 2 == 0 && dayInt > 30) || (monthInt % 2 && dayInt > 31)))
        return (0);
    return (1);
}

bool BitcoinExchange::checkDate(const for_date_check &date)
{
    if (date.year.size() != 4 || is_only_digit(date.year))
        throw(std::runtime_error("Year is invalid"));
    if (date.month.size() != 2 || is_only_digit(date.month) || date.month > "12" || date.month < "01")
        throw(std::runtime_error("Month is invalid"));
    if (date.day.size() != 2 || is_only_digit(date.day) || !checkDay(date))
        throw(std::runtime_error("Day is invalid"));
    return (true);
}

std::pair<std::string, std::string> splitLine(std::stringstream &line, char c)
{
    std::string key;
    std::string val;
    std::getline(line, key, c);
    std::getline(line, val);
    return(std::make_pair(key, val));
}

bool BitcoinExchange::parseData()
{
    std::stringstream ss(_data);
    std::pair<std::string, std::string> pair;
    std::string to;

    if (!_data.empty())
    {
        while (std::getline(ss, to, '\n'))
        {
            pair = splitLine(ss, ',');
        }
    }
}

void BitcoinExchange::fillMap()
{
    double val;
    std::string key;
    // parseData(key, val);
    // if (!splittedKey || !*splittedKey)
    // return ;
    for (int i = 0; i < 3; i++)
    {
        /* code */
    }
}
