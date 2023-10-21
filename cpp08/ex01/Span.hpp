#ifndef _SPAN_HPP
#define _SPAN_HPP


#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <climits>

class Span 
{
    private:
        std::vector<int> _store;
        unsigned int _max_size;
    public:
        Span();
        Span(unsigned int n);
        // Span(Span& object);
        Span& operator=(Span&);
        ~Span();

        void addNumber(int number);
        
        template <typename Container>
        void addNumber(Container begin, Container end)
        {
            int len_to_insert;

            Container tmp_begin = begin;

            for (len_to_insert = 0; tmp_begin != end; tmp_begin++)
                len_to_insert++;
            
            if(_store.size() + len_to_insert > _max_size)
                throw std::out_of_range("container is full");
            
            _store.insert(_store.end(), begin, end);
        }

        std::vector<int>& getStore() ;

        int shortestSpan();
        int longestSpan();
};

#endif