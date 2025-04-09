/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:06:51 by dkremer           #+#    #+#             */
/*   Updated: 2025/03/07 19:23:04 by dkremer          ###   ########.fr       */
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

class Form {
    public:
    Form(string const name, int gradeToSign, int gradeToExecute);
    Form(Form const &other);
    Form &operator=(Form const &other);
    ~Form();

    string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    void beSigned(Bureaucrat const &bureaucrat);
    
    class GradeTooHighException : public std::exception {
        public:
        const char *what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
        public:
        const char *what() const noexcept override;
    };
    private:
        string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;   
};

ostream &operator<<(ostream &os, const Form &form);