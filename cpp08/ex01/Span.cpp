#include "Span.hpp"

Span::Span()
    :_max_size(0)
{

}

Span::Span(unsigned int n)
    :_max_size(n)
{

}

Span::Span(Span& object)
{
    
    *this = object;
}

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

long long Span::shortestSpan() const
{
    std::vector<int> _tmp_store;
    long long shortspan = std::numeric_limits<long>::max();

    _tmp_store = _store;

    std::sort(_tmp_store.begin(), _tmp_store.end());

    for (std::vector<int>::iterator it = _tmp_store.begin(); (it + 1) != _tmp_store.end(); it++)
    {
        long long res = static_cast<long long> (*(it + 1)) - static_cast<long long>(*it);
        if ( res < shortspan)
            shortspan = res;
    }
    return shortspan;
}

long long Span::longestSpan() const
{
    return (static_cast<long long>(*std::max_element(_store.begin(), _store.end())) - static_cast<long long>(*std::min_element(_store.begin(), _store.end())));
}