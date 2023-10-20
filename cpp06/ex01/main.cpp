
#include "Serializer.hpp"

std::ostream& operator<<(std::ostream& out, const Data& object)
{
   out << object.anas << "\n" << object.allo;
   return out;
}

int main()
{
    Data *test = new Data(5,"anas");
    
    std::cout << "befor serilizing \n" << *test << std::endl;
    std::uintptr_t ser = Serializer::serialize(test);
    std::cout << "After serilizing \n" << ser << std::endl;
    Data *dese = Serializer::deserialize(ser);
    std::cout << "After deserilizing \n" << *dese << std::endl;
    std::cout << (test == dese) << std::endl;
}