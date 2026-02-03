#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat alice("Alice", 50);
        ShrubberyCreationForm shrub("garden");

        std::cout << alice << std::endl;
        std::cout << shrub << std::endl;

        alice.signForm(shrub);
        alice.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 40);
        RobotomyRequestForm robot("Bender");
        bob.signForm(robot);
        bob.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat charlie("Charlie", 1);
        PresidentialPardonForm pardon("Nixon");
        charlie.signForm(pardon);
        charlie.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}