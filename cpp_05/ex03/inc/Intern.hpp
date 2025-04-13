#pragma once

#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();
		AForm *makeForm(std::string formName, std::string target);
};

AForm *createPresidentialPardonForm(std::string target);
AForm *createRobotomyRequestForm(std::string target);
AForm *createShrubberyCreationForm(std::string target);
