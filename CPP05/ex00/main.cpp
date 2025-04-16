#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat B("BADER", 1);
    Bureaucrat S("Simo", 2);
    Bureaucrat low("BADER", 150);
    Bureaucrat high("BADER", 1);

    Bureaucrat ran;

    // Bureaucrat too_high("HIGH", 0);
    // Bureaucrat too_low("LOW", 151);

    std::cout << B << std::endl;
    std::cout << S << std::endl;
    std::cout << low << std::endl;
    std::cout << high << std::endl;
    std::cout << ran << std::endl;
}