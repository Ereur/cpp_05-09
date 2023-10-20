#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include <iostream>
#include <exception>

#include "AForm.hpp"

class AForm;

class Intern {

    public :
        Intern();
        Intern(Intern& object);
        Intern& operator=(Intern& object);
        ~Intern();

        AForm* makeForm(const std::string& name, const std::string& target);
        AForm* makeRobotomyForm(const std::string& target);
        AForm* makeShrubberyCreationForm(const std::string& target);
        AForm* makePresidentialPardonForm(const std::string& target);

        class formDosentExist : public std::exception {
            const char* what() const throw() {
                return "Form dose not exist";
            }
        };


};

#endif