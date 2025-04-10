#pragma once

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm {
    public:
    RobotomyRequestForm(std::string const target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(cinst RobotomyRequestForm &other);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const &bureaucrat) const override;
}