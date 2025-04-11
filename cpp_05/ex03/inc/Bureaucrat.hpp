/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:02:50 by dkremer           #+#    #+#             */
/*   Updated: 2025/04/11 14:23:20 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

using std::string;
using std::ostream;

class AForm;

class Bureaucrat
{
    public:
    Bureaucrat(string const name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    
    string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &Aform);
		void executeForm(AForm const &form);
    
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const noexcept override;
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const noexcept override;
    };
    
    private:
        string const _name;
        int _grade;
};

ostream &operator<<(ostream &os, const Bureaucrat &bureaucrat);
