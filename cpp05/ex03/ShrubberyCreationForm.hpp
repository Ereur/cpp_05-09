#ifndef _SHRUBBERYCREATIONFORM_HPP_
#define _SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
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