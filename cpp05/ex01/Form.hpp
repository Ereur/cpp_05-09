#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool Signed;
        const int gradeToSign;
        const int gradeToExec;

    public : 
        Form();
        Form(Form& object);
        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        Form& operator=(Form& object);
        ~Form();

         class GradeTooHighException : public std::exception
        {
            const char* what() const throw(){
                return ("Grade Too High");
            }
        };

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw(){
                return ("Grade Too Low");
            }
        };
        
        const std::string& getName() const;
        const bool& getSigned() const;
        const int& getGradeToSign() const;
        const int& getGradeToExec() const;

        void beSigned(Bureaucrat& object);
};

std::ostream& operator<<(std::ostream& output, Form& object);


#endif