#include "Span.hpp"

int main()
{
    std::vector<int> test;
    
    test.push_back(INT_MAX);
    test.push_back(INT_MIN);
    test.push_back(4);
    test.push_back(90);
    test.push_back(0);
    test.push_back(9);

    Span sp(11);
    
    sp.addNumber(INT_MIN);
    sp.addNumber(INT_MAX-1);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::vector<int>::iterator begin = test.begin();
    std::vector<int>::iterator end = test.end();

    sp.addNumber(begin, end);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

 