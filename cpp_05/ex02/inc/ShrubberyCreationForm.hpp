#pragma once

#include "AForm.hpp"


#define TREE \
"       ###\n\
      #o###\n\
    #####o###\n\
   #o#\#|#/###\n\
    ###\|/#o#\n\
     # }|{  #\n\
       }|{\n"

class AForm;

class ShrubberyCreationform : public AForm {
    public:
        ShrubberyCreationform(std::string const target);
        ShrubberyCreationform(const ShrubberyCreationform &other);
        ShrubberyCreationform &operator=(const ShrubberyCreationform &other);
        ~ShrubberyCreationform();
        void execute(Bureaucrat const &bureaucrat) const override;
};