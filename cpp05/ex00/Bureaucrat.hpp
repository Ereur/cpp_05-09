#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
#include <exception>

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
            virtual const char* what() const throw(){
                return ("Grade Too High");
            }
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw(){
                return ("Grade Too Low");
            }
        };

        const std::string& getName() const;        
        const int& getGrade() const;
        void increment();
        void decrement();
};

std::ostream& operator<<(std::ostream& output, Bureaucrat& object);


#endif