#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Alice", 50);
		std::cout << b << std::endl;

		b.incrementGrade();
		std::cout << b << std::endl;

		b.decrementGrade();
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Charlie", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
