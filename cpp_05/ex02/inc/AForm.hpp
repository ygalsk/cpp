/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:06:51 by dkremer           #+#    #+#             */
/*   Updated: 2025/04/11 14:05:47 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"


#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

using std::string;
using std::ostream;

class Bureaucrat;

class AForm {
    public:
    AForm(string const name, int gradeToSign, int gradeToExecute, string const target);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();

    string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    void beSigned(Bureaucrat const &bureaucrat);
    virtual void execute(Bureaucrat const &bureaucrat) const = 0;
    
    class GradeTooHighException : public std::exception {
        public:
        const char *what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
        public:
        const char *what() const noexcept override;
    };
    class FormNotSignedException : public std::exception {
        public:
        const char *what() const noexcept override;
    };
    class GradeTooLowToExecuteException : public std::exception {
        public:
        const char *what() const noexcept override;
    };
    private:
        string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;   
    protected:
        string const _target;
};

ostream &operator<<(ostream &os, const AForm &form);
