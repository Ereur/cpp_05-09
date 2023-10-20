#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{
    
}

std::uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(std::uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}