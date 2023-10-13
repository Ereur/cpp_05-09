#include "Bureaucrat.hpp"

int main()
{

    try {
        Bureaucrat test("Anas", 10);
        Bureaucrat allo;
        // std::cout << test << std::endl ;
        // test.decrement();
        // std::cout << test.getGrade() << std::endl;
        allo = test;
        std::cout << allo;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "unkown exception" << std::endl;
    }
}