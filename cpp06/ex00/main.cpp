#include "ScalarConverter.hpp"





// A is the base class, and B is derived class
    //downcast
        // saticly casting a pointer of type A to pointer of type B. (its safe to upcast)

    //upcast
        // satiticly casting a pointer of type B to pointer of type A. (its not safe to downcast cause there is a chance of losing data)
    


int main(int ac, char **args)
{

    if (ac > 1)
    {
        ScalarConverter test;
        test.setType(args[1]);
        test.converter();
    }
}

