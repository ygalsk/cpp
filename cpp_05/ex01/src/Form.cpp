/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:23:52 by dkremer           #+#    #+#             */
/*   Updated: 2025/03/07 19:45:41 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Form::Form(string const name, int gradeToSign, int gradeToExecute)
    : _name(name), 
    _signed(false), 
    _gradeToSign(gradeToSign), 
    _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &other) 
    : _name(other._name), 
    _signed(other._signed), 
    _gradeToSign(other._gradeToSign), 
    _gradeToExecute(other._gradeToExecute) {   
    }

Form &Form::operator=(Form const &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form() {
    cout << GREEN << _name << RESET << " Form destroyed" << endl;
}

string Form::getName() const { return this->_name; }

bool Form::isSigned() const { return this->_signed; }

int Form::getGradeToSign() const { return this->_gradeToSign; }

int Form::getGradeToExec() const { return this->_gradeToExecute; }

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

const char *Form::GradeTooHighException::what() const noexcept {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const noexcept {
    return "Grade too low";
}

ostream& operator<<(ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << " requires grade " << form.getGradeToSign() << " to sign and "
       << form.getGradeToExec() << " to execute. "
       << "Status: " << (form.isSigned() ? "signed" : "unsigned");
    return os;
}
