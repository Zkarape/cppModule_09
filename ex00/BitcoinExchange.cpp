#include "BitcoinExchange.hpp"
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <dirent.h>

bool for_date_check::operator==(const for_date_check &obj) const
{
    return (year == obj.year && month == obj.month && day == obj.day);
}

for_date_check &for_date_check::operator=(const for_date_check &obj)
{
    year = obj.year;
    month = obj.month;
    day = obj.day;
    return (*this);
}

void BitcoinExchange::openFile(const std::string &arg)
{
    std::ifstream ifs(arg.c_str());
    if (ifs.is_open())
    {
        std::getline(ifs, _argData, '\0');
        ifs.close();
    }
    else
        throw(std::runtime_error("Bad file argument"));
}

BitcoinExchange::BitcoinExchange() : _data(""), _argData("") {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _map = other._map;
    _data = other._data;
    _argData = other._argData;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _map = other._map;
        _data = other._data;
        _argData = other._argData;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &arg)
{
    openFile(arg);
    openFirstCSV();
}

void BitcoinExchange::openFirstCSV()
{
    DIR *dir;
    struct dirent *ent;
    std::string filename;

    if ((dir = opendir(".")) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            filename = ent->d_name;
            if (filename.size() > 4 && filename.substr(filename.size() - 4) == ".csv")
            {
                std::ifstream ifs(filename.c_str());
                if (!ifs)
                {
                    std::cout << "Error: Could not open file " << filename << std::endl;
                }
                else
                {
                    std::ifstream ifs(filename.c_str());
                    std::getline(ifs, _data, '\0');
                    ifs.close();
                    break;
                }
            }
        }
        closedir(dir);
    }
    else
    {
        std::cout << "Error: Could not open current directory." << std::endl;
    }
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

bool is_leap_year(int year)
{
    return (year % 400 == 0 ? true : year % 100 == 0 ? false
                                 : year % 4 == 0     ? true
                                                     : false);
}

bool checkDay(const for_date_check &date)
{
    char *ptr;

    int dayInt = strtol(date.day.c_str(), NULL, 10);
    if (dayInt <= 0)
        return (0);
    int monthInt = strtol(date.month.c_str(), &ptr, 10);
    if (monthInt <= 7 && ((monthInt % 2 == 0 && dayInt > 30) || (monthInt % 2 && dayInt > 31)))
        return (0);
    if (monthInt == 2 && ((is_leap_year(strtol(date.year.c_str(), &ptr, 10)) == 0 && dayInt > 28) || dayInt > 29))
        return (0);
    if (monthInt > 7 && ((monthInt % 2 == 0 && dayInt > 31) || (monthInt % 2 && dayInt > 30)))
        return (0);
    return (1);
}

inline std::string &strTrim(std::string &str)
{
    str.erase(0, str.find_first_not_of(" "));
    int pos = str.find_last_not_of(" ") + 1;
    str.erase(pos, str.size() - pos);
    return (str);
}

bool BitcoinExchange::checkDate(for_date_check &date)
{
    int k = 1;

    strTrim(date.year);
    strTrim(date.month);
    strTrim(date.day);

    if (date.year.size() != 4 || is_only_digit(date.year) == false || strtol(date.year.c_str(), NULL, 10) < 2009)
        k = 0;
    if (date.month.size() != 2 || is_only_digit(date.month) == false || date.month > "12" || date.month < "01")
        k = 0;
    if (date.day.size() != 2 || is_only_digit(date.day) == false || !checkDay(date))
        k = 0;
    return (k);
}

void aftergetline(std::stringstream &line, const std::string &err)
{
    if (line.fail() == true)
    {
        throw(std::runtime_error(err));
    }
}

int aftergetlinenoexcept(std::stringstream &line, const std::string &date)
{
    int flag = 1;
    if (line.fail() == true)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        flag = 0;
    }
    return (flag);
}

std::pair<std::string, std::string> splitLine(std::string &line, char c)
{
    std::string key;
    std::string val;
    std::stringstream streamLine(line);
    std::getline(streamLine, key, c);

    aftergetline(streamLine, "getline() failed on ','");
    std::getline(streamLine, val);
    return (std::make_pair(key, val));
}

double BitcoinExchange::checkVal(std::string &val)
{
    char *ptr;
    double res;

    // res = strtod(val.c_str(), &ptr);
    res = strtod(strTrim(val).c_str(), &ptr);
    if (*ptr != '\0')
    {
        throw(std::runtime_error("Value is wrong"));
    }
    return (res);
}

void BitcoinExchange::fillMap()
{
    std::stringstream ss(_data);
    std::stringstream ssdate;
    std::pair<std::string, std::string> pair;
    std::string to;
    std::string datestr;
    for_date_check dateStruct;
    double value = 0;

    std::getline(ss, to, '\n');
    pair = splitLine(to, ',');
    if (pair.first != "date" || pair.second != "exchange_rate")
        throw(std::logic_error("data.csv file is not valid"));
    if (!_data.empty())
    {
        while (std::getline(ss, to, '\n'))
        {
            try
            {
                pair = splitLine(to, ',');
                std::stringstream ssdate(pair.first);
                std::getline(ssdate, datestr, '-');
                aftergetline(ssdate, "getline() failed on year");
                dateStruct.year = datestr;
                std::getline(ssdate, to, '-');
                aftergetline(ssdate, "getline() failed on month");
                dateStruct.month = to;
                std::getline(ssdate, to, '\0');
                aftergetline(ssdate, "getline() failed on day");
                dateStruct.day = to;
                if (!checkDate(dateStruct))
                    throw(std::runtime_error("Date is invalid"));
                value = checkVal(pair.second);
                if (value < 0)
                    throw(std::logic_error("Negative value detected in data"));
                _map.insert(std::make_pair(pair.first, value));
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

void BitcoinExchange::printMap() const
{
    std::map<std::string, double>::const_iterator it = _map.begin();

    while (it != _map.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        ++it;
    }
    std::cout << _map.size() << std::endl;
}

double BitcoinExchange::exchange(const std::string &date, float amount) const
{
    std::map<std::string, double>::const_iterator it;

    if (_map.size() < 1)
        throw std::logic_error("there is no data");
    it = _map.lower_bound(date);
    if (it != _map.end())
    {
        return (it->second * amount);
    }
    throw std::logic_error("Not found");
}

bool func(std::string &key, std::string &value)
{
    if (key == "0" && value == "0")
        return (0);
    return (1);
}

void BitcoinExchange::inputParse()
{
    std::stringstream ss(_argData);
    std::stringstream ssdate;
    std::pair<std::string, std::string> pair;
    std::string to;
    for_date_check dateStruct;
    double value = 0;

    std::getline(ss, to, '\n');
    pair = splitLine(to, '|');
    if (pair.first != "date " || pair.second != " value")
        throw(std::logic_error("Input file is not valid"));
    if (!_data.empty())
    {
        while (std::getline(ss, to, '\n'))
        {
            try
            {
                pair = splitLine(to, '|');
                std::stringstream ssdate(pair.first);
                std::getline(ssdate, to, '-');
                dateStruct.year = to;
                std::getline(ssdate, to, '-');
                dateStruct.month = to;
                std::getline(ssdate, to, '\0');
                dateStruct.day = to;
                if (pair.second.empty())
                {
                    std::string s = "Error: bad input => " + pair.first;
                    throw(std::runtime_error(s.c_str()));
                }
                if (pair.second.empty() || !checkDate(dateStruct) || !checkDay(dateStruct))
                {
                    throw(std::runtime_error("Error: bad input"));
                }
                value = checkVal(pair.second);
                if (value < 0)
                    std::cerr << "Error: not a positive number." << std::endl;
                else if (value > 1000)
                    std::cerr << "Error: too large number." << std::endl;
                else
                {
                    double mapvalue = exchange(pair.first, value);
                    std::cout << pair.first << " => " << pair.second << " = " << mapvalue << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

std::ostream &operator<<(std::ostream &out, const for_date_check &instance)
{
    out << instance.year << "-" << instance.month << "-" << instance.day;
    return (out);
}

BitcoinExchange::~BitcoinExchange() {}
