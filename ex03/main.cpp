#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someIntern;
	AForm* form;

	std::cout << "=== Test 1: Create ShrubberyCreationForm ===" << std::endl;
	form = someIntern.makeForm("shrubbery creation", "garden");
	if (form)
	{
		Bureaucrat bob("Bob", 100);
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}

	std::cout << "\n=== Test 2: Create RobotomyRequestForm ===" << std::endl;
	form = someIntern.makeForm("robotomy request", "Marvin");
	if (form)
	{
		Bureaucrat alice("Alice", 40);
		alice.signForm(*form);
		alice.executeForm(*form);
		delete form;
	}

	std::cout << "\n=== Test 3: Create PresidentialPardonForm ===" << std::endl;
	form = someIntern.makeForm("presidential pardon", "Ford");
	if (form)
	{
		Bureaucrat charlie("Charlie", 1);
		charlie.signForm(*form);
		charlie.executeForm(*form);
		delete form;
	}

	std::cout << "\n=== Test 4: Invalid form name ===" << std::endl;
	form = someIntern.makeForm("invalid form", "target");
	if (!form)
		std::cout << "Form creation failed as expected" << std::endl;

	return (0);
}