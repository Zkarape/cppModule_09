#include "RPN.hpp"

// RPN::RPN() {}

// RPN::~RPN() {}

bool isOperator(const std::string &token)
{
    return token.size() == 1 && token.find_first_of("+-*/") != std::string::npos;
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
        return arg2 != 0 ? arg1 / arg2 : 0;
    }
    return 0;
}

double pop(std::stack<double>& stack) {
    if (stack.empty()) {
        throw(std::logic_error("stack is empty\n"));
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
            arg1 = pop(stack);
            arg2 = pop(stack);
            res = invokeOp(token, arg1, arg2);
            if (!std::isnan(res))
            {
                return (res);
            }
            stack.push(res);
        }
        else
        {
            stack.push(stringToDouble(token));
            // stack.push(stod(token));
        }
    }
    return (stack.top());
}
