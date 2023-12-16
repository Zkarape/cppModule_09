#ifndef BE_HPP
# define BE_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

// class RPN
// {
// private:
//     std::stack<int> _stack;

// public:
//     RPN();
//     ~RPN();
//     RPN(const RPN &copy);
//     RPN &operator=(const RPN &assign);
// };


bool IsValidStr(const std::string &src, const std::string &target);
void RPNalgo(std::stack<int> _stack, std::string &);

#endif