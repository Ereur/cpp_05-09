#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : name("Default Bureaucrat"),grade(100)
{
    std::cout << "Bureaucrat Default constructor" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    :name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat parametrized constructor " << std::endl;
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& object)
    :name(object.name), grade(object.grade)
{
    std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat diconstructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& object)
{

    this->grade = object.grade;
    return(*this);
}

std::ostream& operator<<(std::ostream& output, Bureaucrat& object)
{
    output << object.name << ",  bureaucrat grade " << object.grade;
    return output;
}

const std::string& Bureaucrat::getName() const {
    return (this->name);
}

const int& Bureaucrat::getGrade() const {
    return (this->grade);
}

void Bureaucrat::increment(){
    if (this->grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement(){
    if (this->grade == 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form& object)
{
    try 
    {
        object.beSigned(*this);
        std::cout << this->name << " signed " << object.getName() << std::endl;
    }
    catch(std::exception& e)
    {
       std::cout << this->name << " couldn’t sign  " << object.getName() << " because " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "default exception" << std::endl;
    }
}

void Bureaucrat::executeForm(Form const & form) const
{
        try {
            form.execute(*this);
            std::cout << this->name << " executed " << form.getName() << std::endl;
        }
        catch(std::exception& e)
        {
            std::cout << this->name << " couldn’t execute  " << form.getName() << " because " << e.what() << std::endl;
        }
}