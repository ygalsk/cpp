#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Request", 145, 137, target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowToExecuteException();

    std::cout << "* DRILLING NOISES * Bzzzz... Whirr... *" << std::endl;
    std::mt19937 gen(std::random_device{}());
    bool randomSuccess = gen() % 2 == 0;
    if (randomSuccess)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout<< "Robotomy failed for " << this->_target << std::endl;
}