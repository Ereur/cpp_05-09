#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Intern {

    public :
        Intern();
        Intern(Intern& object);
        Intern& operator=(Intern& object);
        ~Intern();

        Form* makeForm(const std::string& name, const std::string& target);
        Form* makeRobotomyForm(const std::string& target);
        Form* makeShrubberyCreationForm(const std::string& target);
        Form* makePresidentialPardonForm(const std::string& target);

        class formDosentExist : public std::exception {
            const char* what() const throw() {
                return "Form dose not exist";
            }
        };


};

#endif