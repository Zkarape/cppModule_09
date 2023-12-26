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
    //         }
    // };

    bool operator==(const for_date_check &obj) const
    {
        return (year == obj.year && month == obj.month && day == obj.day);
    }

    for_date_check &operator=(const for_date_check &obj)
    {
        year = obj.year;
        month = obj.month;
        day = obj.day;
        return (*this);
    }
};

class BitcoinExchange
{
    private:
        std::map<std::string, double> _map;
        std::string _data;
        std::string _argData;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &);
        bool checkDate(for_date_check &_struct);
        double checkVal(std::string &val);
        double exchange(const std::string &date, float amount) const;
        void openFirstCSV();
        void openFile(const std::string &arg);
        void fillMap();
        void inputParse();
        void giveOutput();
        void printMap() const;
        double findInMap(const std::string &) const;
        ~BitcoinExchange();
};

void openFirstCSV();
std::ostream &operator<<(std::ostream &out, const for_date_check &instance);

#endif