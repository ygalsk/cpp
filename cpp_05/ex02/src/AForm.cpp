/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:23:52 by dkremer           #+#    #+#             */
/*   Updated: 2025/04/11 14:41:37 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

AForm::AForm(string const name, int gradeToSign, int gradeToExecute, string const target)
    : _name(name), 
    _signed(false), 
    _gradeToSign(gradeToSign), 
    _gradeToExecute(gradeToExecute),
    _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) 
    : _name(other._name), 
    _signed(other._signed), 
    _gradeToSign(other._gradeToSign), 
    _gradeToExecute(other._gradeToExecute) {   
    }

AForm &AForm::operator=(AForm const &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {
    cout << GREEN << _name << RESET << " AForm destroyed" << endl;
}

string AForm::getName() const { return this->_name; }

bool AForm::isSigned() const { return this->_signed; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExec() const { return this->_gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    _signed = true;
}

const char *AForm::GradeTooHighException::what() const noexcept {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const noexcept {
    return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const noexcept {
	return "Form not sogned";
}

const char *AForm::GradeTooLowToExecuteException::what() const noexcept {
	return "Grade too low to execute";
}

ostream& operator<<(ostream& os, const AForm& form) {
    os << "AForm " << form.getName() 
       << " requires grade " << form.getGradeToSign() << " to sign and "
       << form.getGradeToExec() << " to execute. "
       << "Status: " << (form.isSigned() ? "signed" : "unsigned");
    return os;
}
