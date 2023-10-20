#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm
{
    private:
        const std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(RobotomyRequestForm&);
        RobotomyRequestForm& operator=(RobotomyRequestForm&);
        ~RobotomyRequestForm();

        void    task() const;
};

#endif