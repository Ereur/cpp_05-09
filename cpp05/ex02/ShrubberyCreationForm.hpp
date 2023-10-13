#ifndef _SHRUBBERYCREATIONFORM_HPP_
#define _SHRUBBERYCREATIONFORM_HPP_

#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        const std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(ShrubberyCreationForm&);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm&);
        ~ShrubberyCreationForm();

        void    task() const;
};

#endif