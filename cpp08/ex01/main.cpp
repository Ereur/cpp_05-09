#include "Span.hpp"

int main()
{
    std::vector<int> test;

    test.push_back(6);
    test.push_back(30);
    test.push_back(4);
    test.push_back(90);
    test.push_back(0);
    test.push_back(9);

    Span sp = Span(11);
    
    sp.addNumber(6);
    sp.addNumber(3);
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