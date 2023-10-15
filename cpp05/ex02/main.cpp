#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

    try {
        RobotomyRequestForm test("Rassam");
        Bureaucrat lAariss("Anas", 5);

        lAariss.signForm(test);
        lAariss.executeForm(test);
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