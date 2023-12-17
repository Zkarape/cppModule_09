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
    {
        std::getline(ifs, _data, '\0');
        ifs.close();
    }
    else
        throw(std::runtime_error("Bad file input"));
}

BitcoinExchange::BitcoinExchange(const std::string &arg)
{
    (void)arg;
    openFile("data.csv");
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

bool is_leap_year(int year) {
    return (year % 400 == 0 ? true : year % 100 == 0 ? false : year % 4 == 0 ? true : false);
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
    if (monthInt > 7 && ((monthInt % 2 == 0 && dayInt > 31) || (monthInt % 2 && dayInt > 30)))
        return (0);
    return (1);
}

bool BitcoinExchange::checkDate(const for_date_check &date)
{
    if (date.year.size() != 4 || is_only_digit(date.year) == false)
        throw(std::runtime_error("Year is invalid"));
    if (date.month.size() != 2 || is_only_digit(date.month) == false || date.month > "12" || date.month < "01")
        throw(std::runtime_error("Month is invalid"));
    if (date.day.size() != 2 || is_only_digit(date.day) == false || (!checkDay(date) && printf("checkDay\n")))
        throw(std::runtime_error("Day is invalid"));
    return (true);
}

void aftergetline(std::stringstream &line, const std::string &err)
{
    if (line.fail() == true)
        throw(std::runtime_error(err));
}

std::pair<std::string, std::string> splitLine(std::string line, char c)
{
    std::string key;
    std::string val;
    std::stringstream streamLine(line);
    std::getline(streamLine, key, c);
    aftergetline(streamLine, "Getline failed on ','");
    std::getline(streamLine, val);
    aftergetline(streamLine, "Error on getline()");
    return (std::make_pair(key, val));
}

double BitcoinExchange::checkVal(const std::string &val)
{
    char *ptr;
    double res;

    res = strtod(val.c_str(), &ptr);
    if (*ptr != '\0')
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
            try
            {
                pair = splitLine(to, ',');
                std::stringstream ssdate(pair.first);
                std::getline(ssdate, toDateStr, '-');
                aftergetline(ssdate, "getline() failed on year");
                dateStruct.year = toDateStr;
                std::getline(ssdate, toDateStr, '-');
                aftergetline(ssdate, "getline() failed on month");
                dateStruct.month = toDateStr;
                std::getline(ssdate, toDateStr, '\0');
                aftergetline(ssdate, "getline() failed on day");
                dateStruct.day = toDateStr;
                checkDate(dateStruct);
                value = checkVal(pair.second);
                _map.insert(std::make_pair(pair.first, value));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

void BitcoinExchange::printMap() const {
    std::map<std::string, double>::const_iterator it = _map.begin();

    while (it != _map.end()) {
        std::cout << it->first << " " << it->second << std::endl;
        ++it;
    }
    std::cout << _map.size() << std::endl;
};

void BitcoinExchange::giveOutput()
{

}


std::ostream&	operator<<(std::ostream& out, const for_date_check& instance)
{
	out << instance.year << "-" << instance.month << "-" << instance.day;
	return (out);
}
