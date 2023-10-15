#include "Bureaucrat.hpp"

int main()
{

    try {
        // Bureaucrat low("Anas", 150);
        // low.decrement();
        // std::cout << low << std::endl;

        Bureaucrat high("Anas", 1);
        high.increment();
        std::cout << high;

    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Default exception" << std::endl;
    }
}