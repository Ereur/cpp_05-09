#ifndef _EASYFIND_HPP
#define _EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& ContainerInteger, const int& sec)
{
    typedef typename T::iterator iter;

    iter it = std::find(ContainerInteger.begin(), ContainerInteger.end(), sec);
    if(it == ContainerInteger.end())
        throw std::range_error("not found");
    return (it);
}


#endif