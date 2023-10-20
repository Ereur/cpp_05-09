
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
    int i = easyfind(allo,0);
    std::cout << i << std::endl;

    std::list<int> allo1;
    allo1.push_back(2);
    allo1.push_back(1);
    allo1.push_back(3);
    allo1.push_back(4);
    allo1.push_back(5);
    int i1 = easyfind(allo1,43);
    std::cout << i1 << std::endl;


}