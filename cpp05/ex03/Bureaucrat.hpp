#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {

    public:
        const std::string name;
        int grade;

        Bureaucrat();
        Bureaucrat(Bureaucrat& object);
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& object);

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
        const int& getGrade() const;
        void increment();
        void decrement();

        void signForm(Form& object);

        void executeForm(Form const & form) const;
};

std::ostream& operator<<(std::ostream& output, Bureaucrat& object);


#endif