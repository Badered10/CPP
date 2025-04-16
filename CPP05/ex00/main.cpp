#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat B("BADER", 1);
    Bureaucrat S("Simo", 2);
    Bureaucrat low("BADER", 150);
    Bureaucrat high("high", 1);

    Bureaucrat ran;

    // Bureaucrat too_high("HIGH", 0);
    // Bureaucrat too_low("LOW", 151);
    low.incrementGrade();

    std::cout << B << std::endl;
    std::cout << S << std::endl;
    std::cout << low << std::endl;
    std::cout << high << std::endl;
    std::cout << ran << std::endl;

    low.incrementGrade();

    // high.incrementGrade();
}