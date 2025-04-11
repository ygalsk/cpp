#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential Pardon", 25, 5, target) {
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
if (this != &other)
        AForm::operator=(other);
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (bureaucrat.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox";
}
