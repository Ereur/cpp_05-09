
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> allo;
    allo.push_back(2);
    allo.push_back(1);
    allo.push_back(3);
    allo.push_back(4);
    allo.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(allo,4);
        std::cout << *it << std::endl;
    }
    catch(...)
    {
        std::cout << "NOT FOUND";
    }


    std::list<int> allo1;
    allo1.push_back(2);
    allo1.push_back(1);
    allo1.push_back(3);
    allo1.push_back(4);
    allo1.push_back(5);
    try
    {
        std::list<int>::iterator it1 = easyfind(allo1,43);
        std::cout << *it1 << std::endl;
    }
    catch(...)
    {
        std::cout << "NOT FOUND";
    }

}