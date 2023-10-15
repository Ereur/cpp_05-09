#ifndef _PRESIDENTIALPARDONFORM_HPP
#define _PRESIDENTIALPARDONFORM_HPP


#include "Form.hpp"

class PresidentialPardonForm : public Form 
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