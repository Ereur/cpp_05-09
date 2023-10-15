#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){

}

Intern::Intern(Intern& object)
{
    (void)object;
}

Intern& Intern::operator=(Intern& object)
{
    (void)object;
    return (*this);
}

Intern::~Intern()
{

}

Form* Intern::makeRobotomyForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

Form* Intern::makeShrubberyCreationForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

Form* Intern::makePresidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

typedef Form*(Intern::*Function)(const std::string& target);

// Form* test = ((*this).*(form))(target);

Form* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string formNames[3] = {"robotomy request","presidential pardon","shrubbery creation"};    
    Function forms[3] = {&Intern::makeRobotomyForm, &Intern::makePresidentialPardonForm, &Intern::makeShrubberyCreationForm};

    int i = 0;

    Form *type;

    while (i < 3)
    {
        if (name == formNames[i])
            break;
        i++;
    }

    switch(i)
    {
        case 0:
            type = ((*this).*(forms[i]))(target);
            break;
        case 1:
            type = ((*this).*(forms[i]))(target);
            break;
        case 2:
            type = ((*this).*(forms[i]))(target);
            break;
        default:
            throw formDosentExist();
    }
    std::cout << "Intern creates \n" << *type << std::endl; 
    return type;
}
