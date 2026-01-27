#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Invalid", 0);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("Invalid", 151);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
