#pragma once

#include "AForm.hpp"
#include <random>
#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class AForm;

class RobotomyRequestForm : public AForm {
    public:
    RobotomyRequestForm(std::string const target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const &bureaucrat) const override;
};