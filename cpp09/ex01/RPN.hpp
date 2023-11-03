#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN
{
    private:
        std::stack<int> s;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& object);
        RPN& operator=(const RPN& object);
        int evaluateRPN(const std::string& expr);
};