#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("Shrubbery Creation", 145, 137, target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const {
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowToExecuteException();

    std::ofstream file(this->_target + "_shrubbery");
    if (!file.is_open())
        throw std::runtime_error("Error: couldnt open file");
    file << TREE;
    file.close();
    std::cout << "Shrubbery file created successfully!" << std::endl;
}