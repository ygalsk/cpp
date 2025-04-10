#pragma once

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonFor &other);
        ~PresidentialPardonform();
        void execute(Bureaucrat const &bureaucrat) const override;
}