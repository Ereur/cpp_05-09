#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    :name("Default AForm") , Signed(false),gradeToSign(150), gradeToExec(150) 
{
    std::cout << "AForm Default constructor" << std::endl;
}

AForm::AForm(AForm& object)
    :name(object.name), Signed(false), gradeToSign(object.gradeToSign), gradeToExec(object.gradeToExec)
{
    std::cout << "AForm copy constructor" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec)
    :name(name), Signed(false),gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "AForm Parametrized constructor" << std::endl;
}

AForm& AForm::operator=(AForm& object)
{
    this->Signed = object.Signed;
    return(*this);
}

AForm::~AForm()
{
    std::cout << "AForm deconstructor" << std::endl;
}

const std::string& AForm::getName() const
{
    return (this->name);
}
const bool& AForm::getSigned() const
{
    return (this->Signed);
}
const int& AForm::getGradeToSign() const
{
    return(this->gradeToSign);
}

const int& AForm::getGradeToExec() const
{
    return(this->gradeToExec);
}
    
std::ostream& operator<<(std::ostream& output, AForm& object){

    output << " name: " << object.getName() << "\n" << " gradeTosIgn: " << object.getGradeToSign() << "\n" << " gradeToExec: " << object.getGradeToExec() << "\n" << " Signed: " << object.getSigned();
    return (output);
}

void AForm::beSigned(Bureaucrat& object)
{
    if (object.getGrade() <= this->gradeToSign)
        this->Signed = true;
    else
    {
        throw GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->Signed)
    {
        if (executor.getGrade() <= this->gradeToExec)
            this->task();
        else
            throw GradeTooLowException();
    }
}
