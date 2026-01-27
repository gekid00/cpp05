#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat alice("Alice", 30);
		Form form("Tax Form", 50, 25);

		std::cout << form << std::endl;
		alice.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 100);
		Form form("High Level Form", 50, 25);

		bob.signForm(form);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form invalidForm("Invalid", 0, 50);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
