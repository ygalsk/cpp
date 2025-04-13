#include "Intern.hpp"

Intern::Intern() {
		// std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other) {
	(void)other;
	// std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other) {
	(void)other;
	// std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	// std::cout << "Intern destructor called" << std::endl;
}

AForm* createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}
