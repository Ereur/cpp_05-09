#ifndef _AForm_HPP_
#define _AForm_HPP_

#include <iostream>
#include <exception>
#include <fstream>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool Signed;
        const int gradeToSign;
        const int gradeToExec;

    public : 
        AForm();
        AForm(AForm& object);
        AForm(const std::string name, const int gradeToSign, const int gradeToExec);
        AForm& operator=(AForm& object);
        ~AForm();

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
        void execute(Bureaucrat const & executor) const;
        virtual void task() const = 0;

};

std::ostream& operator<<(std::ostream& output, AForm& object);


#endif