#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
    :AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm Default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    :AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm Parametrized constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& object)
{
    (void)object;
    std::cout << "PresidentialPardonForm Copy constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& object)
{
    (void)object;
    std::cout << "PresidentialPardonForm Copy assignment constructor" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm distructor" << std::endl;
}

void PresidentialPardonForm::task() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}