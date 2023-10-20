#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}


void	ScalarConverter::setType(const std::string& literal)
{
    if(!literal.empty())
    {
        if (!std::isdigit(literal[0]))
        {
            type = CHAR;
            _char = literal[0];
        }   
        else if (literal.find('f') < literal.length() && literal.find('.') < literal.length())
        {
            type = FLOAT;
            _float = std::stof(literal);
        }   
        else if (literal.find('.') < literal.length())
        {
            type = DOUBLE;
            _double = std::stod(literal);
        }
        else
        {
            type = INT;
            _int = std::stoi(literal);
        }
    }

}

void ScalarConverter::converter()
{
    if (type == CHAR)
    {
        std::cout << "char: " << static_cast<char> (_char)<< std::endl;
        std::cout << "int: " << static_cast<int> (_char) << std::endl;
        std::cout << "float: " << static_cast<float> (_char) << std::endl;
        std::cout << "double: " << static_cast<double> (_char) << std::endl;
    }
    else if (type == FLOAT)
    {
        std::cout << "char: " << static_cast<char> (_float)<< std::endl;
        std::cout << "int: " << static_cast<int> (_float) << std::endl;
        std::cout << "float: " << static_cast<float> (_float) << std::endl;
        std::cout << "double: " << static_cast<double> (_float) << std::endl;
    }
    else if (type == DOUBLE)
    {
        std::cout << "char: " << static_cast<char> (_double)<< std::endl;
        std::cout << "int: " << static_cast<int> (_double) << std::endl;
        std::cout << "float: " << static_cast<float> (_double) << std::endl;
        std::cout << "double: " << static_cast<double> (_double) << std::endl;
    }
    else if (type == INT)
    {
        std::cout << "char: " << static_cast<char> (_int)<< std::endl;
        std::cout << "int: " << static_cast<int> (_int) << std::endl;
        std::cout << "float: " << static_cast<float> (_int) << std::endl;
        std::cout << "double: " << static_cast<double> (_int) << std::endl;
    }

}