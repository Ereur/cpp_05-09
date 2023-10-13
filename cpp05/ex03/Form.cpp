#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    :name("Default Form") , Signed(false),gradeToSign(150), gradeToExec(150) 
{
    std::cout << "Form Default constructor" << std::endl;
}

Form::Form(Form& object)
    :name(object.name), Signed(false), gradeToSign(object.gradeToSign), gradeToExec(object.gradeToExec)
{
    std::cout << "Form copy constructor" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec)
    :name(name), Signed(false),gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "Form Parametrized constructor" << std::endl;
}

Form& Form::operator=(Form& object)
{
    this->Signed = object.Signed;
    return(*this);
}

Form::~Form()
{
    std::cout << "Form deconstructor" << std::endl;
}

const std::string& Form::getName() const
{
    return (this->name);
}
const bool& Form::getSigned() const
{
    return (this->Signed);
}
const int& Form::getGradeToSign() const
{
    return(this->gradeToSign);
}

const int& Form::getGradeToExec() const
{
    return(this->gradeToExec);
}
    
std::ostream& operator<<(std::ostream& output, Form& object){

    output << " name: " << object.getName() << "\n" << " gradeTosIgn: " << object.getGradeToSign() << "\n" << " gradeToExec: " << object.getGradeToExec() << "\n" << " Signed: " << object.getSigned();
    return (output);
}

void Form::beSigned(Bureaucrat& object)
{
    if (object.getGrade() <= this->gradeToSign)
        this->Signed = true;
    else
    {
        throw GradeTooLowException();
    }
}

void Form::execute(Bureaucrat const & executor) const
{
    if (this->Signed)
    {
        if (executor.getGrade() <= this->gradeToExec)
            this->task();
        else
            throw GradeTooLowException();
    }
}
