#ifndef _EASYFIND_HPP
#define _EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <class T>
int& easyfind(T& ContainerInteger, const int& sec)
{
    typedef typename T::iterator iter;

    iter it = std::find(ContainerInteger.begin(), ContainerInteger.end(), sec);
    return (*it);
}

#endif