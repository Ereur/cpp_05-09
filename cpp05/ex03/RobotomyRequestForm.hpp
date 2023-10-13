#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public Form
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