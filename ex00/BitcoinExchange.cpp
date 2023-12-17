#include "BitcoinExchange.hpp"
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>

void BitcoinExchange::openFile(const std::string &arg)
{
    std::ifstream ifs(arg);
    if (ifs.is_open())
        ifs.close();
    else
        throw(std::runtime_error("Bad file input"));
    ifs >> _data;
}

BitcoinExchange::BitcoinExchange(const std::string &arg)
{
    openFile(arg);
}

BitcoinExchange::~BitcoinExchange() {}

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

void aftergetline(std::stringstream &line, const std::string &err)
{
    if (line.good() == false)
        throw(std::runtime_error(err));
}

std::pair<std::string, std::string> splitLine(std::stringstream &line, char c)
{
    std::string key;
    std::string val;
    std::getline(line, key, c);
    aftergetline(line, "Getline failed on ','");
    std::getline(line, val);
    aftergetline(line, "Error on getline()");
    return (std::make_pair(key, val));
}

double BitcoinExchange::checkVal(const std::string &val)
{
    char *ptr;
    double res;

    res = strtod(val.c_str(), &ptr);
    if (ptr != NULL)
        throw(std::runtime_error("Value is wrong"));
    return (res);
}

void BitcoinExchange::fillMap()
{
    std::stringstream ss(_data);
    std::stringstream ssdate;
    std::pair<std::string, std::string> pair;
    std::string to;
    std::string toDateStr;
    for_date_check dateStruct;
    double value = 0;

    if (!_data.empty())
    {
        while (std::getline(ss, to, '\n'))
        {
            pair = splitLine(ss, ',');
            std::stringstream ssdate(pair.first);
            std::getline(ssdate, toDateStr, '-');
            aftergetline(ssdate, "getline() failed on year");
            dateStruct.year = toDateStr;
            std::getline(ssdate, toDateStr, '-');
            aftergetline(ssdate, "getline() failed on month");
            dateStruct.month = toDateStr;
            std::getline(ssdate, toDateStr);
            aftergetline(ssdate, "getline() failed on day");
            dateStruct.day = toDateStr;
            checkDate(dateStruct);
            value = checkVal(pair.second);
            _map.insert(std::make_pair(dateStruct, value));
        }
    }
}

