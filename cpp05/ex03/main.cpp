#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{

    try {
        Intern Robotomy;
        Form* Robo;
        Robo = Robotomy.makeForm("robotomy request", "Bender");
    
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Waa3");

        Intern Shrubbery;
        Form* shru;
        shru = Shrubbery.makeForm("shrubbery creation", "biip");
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