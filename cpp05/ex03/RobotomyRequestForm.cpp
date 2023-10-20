#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
    :AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm Default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    :AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm Parametrized constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& object)
{
    (void)object;
    std::cout << "RobotomyRequestForm Copy constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& object)
{
    (void)object;
    std::cout << "RobotomyRequestForm Copy assignment constructor" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm distructor" << std::endl;
}

void RobotomyRequestForm::task() const
{
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized " << std::endl;
    else
        std::cout << this->target << " has been failed " << std::endl;
}