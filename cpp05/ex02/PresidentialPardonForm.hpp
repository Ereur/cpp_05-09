#ifndef _PRESIDENTIALPARDONFORM_HPP
#define _PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    private:
        const std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(PresidentialPardonForm&);
        PresidentialPardonForm& operator=(PresidentialPardonForm&);
        ~PresidentialPardonForm();

        void task() const;
};

#endif