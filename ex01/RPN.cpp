#include "RPN.hpp"

// RPN::RPN() {}

// RPN::~RPN() {}

bool IsValidStr(const std::string& source, const std::string& target)
{
    int srcLen = source.length();
    char **splitted = ;

    for (int i = 0; i < srcLen; i++)
    {
        if (target.find(source[i]) == std::string::npos)
            return (0);
    }

    return 1;
}

void RPNalgo(std::stack<int> _stack, std::string &str)
{
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (isdigit(str[i]))
        {
            _stack.push(str[i]);
        }

    }
    
}
