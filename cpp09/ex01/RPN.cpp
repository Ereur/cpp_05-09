#include "RPN.hpp"

int RPN::evaluateRPN(const std::string& expr)
{
    
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token)
    {
        if (std::isdigit(token[0]))
        {
            // convert token to integer and push into stack
            std::stringstream convert(token);
            int i ;
            convert >> i;
            s.push(i);
        }
        else
        {
            // token is an operator, pop two operands from stack and apply operator
            if (s.size() < 2)
                throw std::invalid_argument("Invalid expression: " + expr);
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();

            if (token == "+")
                s.push(op1 + op2);
            else if (token == "-")
                s.push(op1 - op2);
            else if (token == "*")
                s.push(op1 * op2);
            else if (token == "/")
                s.push(op1 / op2);
            else
                throw std::invalid_argument("Invalid operator: " + token);
        }
    }

    // the result is the only element left on the stack
    if (s.size() != 1)
        throw std::invalid_argument("Invalid expression: " + expr);

    return s.top();
}

RPN::RPN()
{    
}

RPN::~RPN()
{

}

RPN::RPN(const RPN& object)
{
    *this = object;
}

RPN& RPN::operator=(const RPN& object)
{
    this->s = object.s;
    return (*this);
}
