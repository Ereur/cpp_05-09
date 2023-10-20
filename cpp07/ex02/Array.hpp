#ifndef _ARRAY_HPP
#define _ARRAY_HPP

#include <exception>
#include <iostream>
#include <stdexcept>

template <class T>
class Array 
{
    private:
        T *arr;
        int len;

    public:
        Array()
        {
            this->arr = NULL;
            this->len = 0;
        }

        Array(unsigned int n)
        {
            if (n < 0)
                throw std::out_of_range("out of range");
            arr = new T[n]();
            this->len = n;
        }
        Array(const Array &object)
        {
            *this = object;
        }

        ~Array()
        {
            if (this->arr)
                delete [] arr;
        }   
        
        Array& operator=(const Array &object)
        {
            if(!this->len)
            {
                this->arr = NULL;
                this->len = 0;
                return (*this);
            }
            this->arr = new T[object.size()]();
            for (int i = 0; i < object.len; i++)
            { 
                arr[i] = object[i];
            }
            this->len = object.size();
            return (*this);
        }

        T& operator[](const int &indx) const
        {
            if (indx < 0 || indx >= len)
                throw std::out_of_range("out of range");
            return(arr[indx]);
        }

        const int& size() const
        {
            return (this->len);
        } 
};

#endif