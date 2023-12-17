#ifndef BE_HPP
#define BE_HPP

#include <iostream>
#include <map>

struct for_date_check
{
    std::string year;
    std::string month;
    std::string day;

    class compare
    {
        public:
            bool operator()(const for_date_check &obj1, const for_date_check &obj2) const {
                return (obj1.year < obj2.year && obj1.month < obj2.month && obj1.day < obj2.day);
            }
    };

    // bool operator<(const for_date_check &obj) const {
    //     return (year == obj.year && month == obj.month && day == obj.day);
    // }
};

class BitcoinExchange
{
private:
    std::map<for_date_check, double, for_date_check::compare> _map;
    std::string _data;
    // char **_keys;
public:
    BitcoinExchange();
    BitcoinExchange(const std::string &arg);
    bool checkDate(const for_date_check &_struct);
    double checkVal(const std::string &val);
    ~BitcoinExchange();
    void openFile(const std::string &arg);
    void fillMap();
    
};

#endif