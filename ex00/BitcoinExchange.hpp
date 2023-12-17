#ifndef BE_HPP
#define BE_HPP

#include <iostream>
#include <map>

struct for_date_check
{
    std::string year;
    std::string month;
    std::string day;

    // class compare
    // {
    //     public:
    //         bool operator()(const for_date_check &obj1, const for_date_check &obj2) const {
    //             if (obj1.year < obj2.year)
    //                 return (1);
    //             if (obj1.year == obj2.year && obj1.month < obj2.month)
    //                 return (1);
    //             if (obj1.year == obj2.year && obj1.month == obj2.month && obj1.day < obj2.day)
    //                 return (1);
    //             return 0;
    //             // return (obj1.year < obj2.year || obj1.month < obj2.month || obj1.day < obj2.day);
    //         }
    // };


    bool operator==(const for_date_check &obj) const {
        return (year == obj.year && month == obj.month && day == obj.day);
    }

    bool operator<(const for_date_check &obj) const {
        if (year < obj.year)
            return (1);
        if (year == obj.year)
        {
            if (month < obj.month)
                return true;
            if (month == obj.month)
            {
                if (day < obj.day)
                    return true;
            }
        }
        return 0;
    }

    for_date_check& operator=(const for_date_check &obj) {
        year = obj.year;
        month = obj.month;
        day = obj.day;
        return (*this);
    }
    
};

std::ostream&	operator<<(std::ostream& out, const for_date_check& instance);

class BitcoinExchange
{
private:
    std::map<std::string, double, std::greater<std::string> > _map;
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
    void giveOutput();
    void printMap() const;
};

#endif