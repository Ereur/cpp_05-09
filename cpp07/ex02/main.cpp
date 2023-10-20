#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<std::string> test(5);;

    for(int i = 0; i < 5; i++)
    {
        test[i] = "Anas";
        std::cout << test[i] << std::endl;
    }
    std::cout << test.size() << std::endl;
}