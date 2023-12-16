#ifndef BE_HPP
# define BE_HPP

#include <cassert>
#include <cmath> // std::isnan
#include <iostream>
#include <limits>
#include <sstream> // std::istringstream
#include <stack>
#include <string>
#include <cfloat>




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