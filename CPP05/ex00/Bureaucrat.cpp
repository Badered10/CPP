#include "Bureaucrat.hpp"
#include <ctime>

void Bureaucrat::GradeChecker (int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
     else if (grade < 1)
        throw GradeTooHighException();
    this->grade = grade;
}

// constractors and destractors

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    GradeChecker(grade);
}

Bureaucrat::Bureaucrat() : name("Unnamed")
{
    time_t now;
    time(&now);
    std::tm *local_time = std::localtime(&now);
    this->grade = abs(1 + ( (local_time->tm_sec * std::rand()) % 150 ));
    GradeChecker(this->grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat & other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {}

// opreators

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}
std::ostream & operator<<(std::ostream & s, const Bureaucrat & obj)
{
    s << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (s);
}

// geters 

std::string Bureaucrat::getName(void) const {return (name);}

int Bureaucrat::getGrade(void) const {return (grade);}


// incr and deincr methods

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat::deincrementGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    grade++;
}

// exceptions

const char * Bureaucrat::GradeTooHighException::what() const throw() {return ("Grade too high ! the highest vlaue is 1");}

const char * Bureaucrat::GradeTooLowException::what() const throw() {return ("Grade too low ! the lowest vlaue is 150");}
