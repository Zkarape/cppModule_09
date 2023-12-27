#ifndef BE_HPP
# define BE_HPP

#include <iostream>
#include <map>

struct for_date_check
{
    std::string year;
    std::string month;
    std::string day;
    bool operator==(const for_date_check &obj) const;
    for_date_check &operator=(const for_date_check &obj);
};

class BitcoinExchange
{
    private:
        std::map<std::string, double, std::greater<std::string> > _map;
        std::string _data;
        std::string _argData;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &);
        BitcoinExchange(const BitcoinExchange &);
        BitcoinExchange &operator=(const BitcoinExchange &);
        bool checkDate(for_date_check &_struct);
        double checkVal(std::string &val);
        double exchange(const std::string &date, float amount) const;
        void openFirstCSV();
        void openFile(const std::string &arg);
        void fillMap();
        void inputParse();
        void printMap() const;
        ~BitcoinExchange();
};

std::ostream &operator<<(std::ostream &out, const for_date_check &instance);

#endif
