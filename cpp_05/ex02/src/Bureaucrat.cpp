#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iomanip>

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat(string const name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    cout << GREEN << _name << RESET << " Bureaucrat created" << endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
    cout << GREEN << _name << RESET << " Bureaucrat copied" << endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
    if (this != &other) {
        _grade = other._grade;
    }
    cout << GREEN << _name << RESET << " Bureaucrat assigned" << endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    cout << GREEN << _name << RESET << " Bureaucrat destroyed" << endl;
}

string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
    cout << GREEN << _name << RESET << " Bureaucrat grade incremented to " << _grade 
        << endl;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
    cout << GREEN << _name << RESET << " Bureaucrat grade decremented to " << _grade << endl;
}

void Bureaucrat::signForm(AForm& Aform) {
    try {
        Aform.beSigned(*this);
        cout << GREEN << _name << RESET << " signed " 
             << GREEN << Aform.getName() << RESET << endl;
    }
    catch (const std::exception& e) {
        cout << RED << _name << RESET << " couldn't sign " 
             << RED << Aform.getName() << RESET << " because " 
             << e.what() << endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
	}
	catch(const std::exception &e) {
		std::cerr << "Bureaucrat " << this->getName() << " failed to execute " << form.getName() << " > Bureaucrat " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat " << this->getName() << " executed " << form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade too low";
}

ostream &operator<<(ostream &os, const Bureaucrat &bureaucrat) {
    os << GREEN << bureaucrat.getName() << RESET << ", bureaucrat grade " 
       << GREEN << bureaucrat.getGrade() << RESET;
    return os;
}
