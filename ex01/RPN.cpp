#include "RPN.hpp"

bool isOperator(const std::string &token)
{
    bool res = token.find_first_of("+-*/") != std::string::npos;
    if(token.size() != 1 || (std::isdigit(token[0]) == false && res == false))
        throw(std::logic_error("Token size is invalid"));
    return res;
}

double invokeOp(const std::string &token, double arg1, double arg2)
{
    assert(token.size() == 1);
    switch (token[0])
    {
    case '+':
        return arg1 + arg2;
    case '-':
        return arg1 - arg2;
    case '*':
        return arg1 * arg2;
    case '/':
        return arg2 != 0 ? arg1 / arg2 : throw(std::logic_error("Divided by 0"));
    }
    return 0;
}

double pop(std::stack<double>& stack) {
    if (stack.empty()) {
        throw(std::logic_error("Stack is empty"));
    }
    double arg = stack.top();
    stack.pop();
    return arg;
}

double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    return result;
}

double RPNalgo(const std::string &expression)
{
    std::istringstream istr(expression);
    std::string token;
    std::stack<double> stack;
    double arg1;
    double arg2;
    double res;

    while (istr >> token)
    {
        if (isOperator(token))
        {
            arg2 = pop(stack);
            arg1 = pop(stack);
            res = invokeOp(token, arg1, arg2);
            stack.push(res);
        }
        else
        {
        assert(token.size() == 1);
            stack.push(stringToDouble(token));
        }
    }
    if (stack.size() != 1)
        throw(std::logic_error("Stack is not empty"));
    return (stack.top());
}
