#ifndef _SERIALIZER_HPP
#define _SERIALIZER_HPP

#include<iostream>

struct Data {
    int anas;
    std::string allo;
    Data(int a, const std::string& b)
    {
        anas = a;
        allo = b;
    }
};

class Serializer {

    private:
        Serializer();
        ~Serializer();
    public:
        static std::uintptr_t serialize(Data* ptr);
        static Data* deserialize(std::uintptr_t raw);
};



#endif