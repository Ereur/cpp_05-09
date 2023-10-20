#ifndef _ITER_HPP
#define _ITER_HPP

#include <iostream>

template <typename T, typename B>
void iter(T* add,int len, B fun)
{
    for (int i = 0; i < len; i++)
    {
        fun(add[i]);
    }
}

#endif

