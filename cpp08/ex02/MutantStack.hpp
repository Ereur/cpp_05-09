#ifndef _MUTANSTACK_HPP_
#define _MUTANSTACK_HPP_

#include <iostream>
#include <stack>
#include <deque>

template<
    typename T,
    typename Container = std::deque<T> 
    >
class MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack& copy) { *this = copy;}
		MutantStack& operator=(const MutantStack& copy) { this->c = copy.c; return (*this); }
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;

		iterator begin() {
            
            return (std::stack<T>::c.begin()); 
        
        }

		iterator end() { 
            return (std::stack<T>::c.end()); 
        }
		
		const_iterator cbegin() 
        {
            return (std::stack<T>::c.cbegin()); 
        }
		
        const_iterator cend() { 
            return (std::stack<T>::c.cend()); 
        }
};


#endif