/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:02:50 by dkremer           #+#    #+#             */
/*   Updated: 2025/03/04 16:21:02 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::ostream;

class Bureaucrat
{
    public:
    Bureaucrat(string const name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
        
    string const getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw() override;
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw() override;
    };
    
    private:
        string const _name;
        int _grade;
};

ostream &operator<<(ostream &os, const Bureaucrat &bureaucrat);