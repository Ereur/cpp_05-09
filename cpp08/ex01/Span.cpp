#include "Span.hpp"

Span::Span()
    :_max_size(0)
{

}

Span::Span(unsigned int n)
    :_max_size(n)
{

}

// Span::Span(Span& object)
// {
    
//     *this = object;
// }

Span& Span::operator=(Span& object)
{
    _max_size = object._max_size;
    _store = object._store;
    return (*this);
}

Span::~Span()
{

}

std::vector<int>& Span::getStore() 
{
    return (_store);
}

void Span::addNumber(int number)
{
    if (_store.size() == _max_size)
        throw std::out_of_range("container is full");
    _store.push_back(number);
}

int Span::shortestSpan()
{
    std::vector<int> _tmp_store;
    int shortspan = INT_MAX;

    _tmp_store = _store;

    std::sort(_tmp_store.begin(), _tmp_store.end());

    for (std::vector<int>::iterator it = _tmp_store.begin(); (it + 1) != _tmp_store.end(); it++)
    {
        int res = *(it + 1) - *it;
        if ( res < shortspan)
            shortspan = res;
    }
    return shortspan;
}

int Span::longestSpan()
{
    return (*std::max_element(_store.begin(), _store.end()) - *std::min_element(_store.begin(), _store.end()));
}