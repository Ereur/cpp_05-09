#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    try {
        Form test("3a9edzwaj", 10, 15);
        Bureaucrat lAariss("Anas", 151);

        lAariss.signForm(test);
    
        // std::cout << test << std::endl;
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