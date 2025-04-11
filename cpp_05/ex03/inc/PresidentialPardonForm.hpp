#pragma once

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const &bureaucrat) const override;
};
