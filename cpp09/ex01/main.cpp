#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Error: " << std::endl;
        return 1;
    }
    try
    {
        RPN eval;
        std::string expr(av[1]);
        int result = eval.evaluateRPN(expr);
        std::cout << "Result: " << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}