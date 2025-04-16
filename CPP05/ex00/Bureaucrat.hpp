#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdlib.h>

class Bureaucrat
{
    private:
        void GradeChecker(int grade);
        const std::string name;
        int grade;

    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat();
        Bureaucrat(const Bureaucrat & other);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat & other);
        
        std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void deincrementGrade(void);
        class GradeTooHighException : public std::exception
        {
            public:
            const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
            const char * what() const throw();
        };
};
    
std::ostream & operator<<(std::ostream & s, const Bureaucrat & obj);

#endif