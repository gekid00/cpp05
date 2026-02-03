#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat alice("Alice", 50);
		Form form1("TaxForm", 100, 50);

		std::cout << alice << std::endl;
		std::cout << form1 << std::endl;

		alice.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bob("Bob", 150);
		Form form2("ImportantForm", 100, 50);

		std::cout << "\n" << bob << std::endl;
		std::cout << form2 << std::endl;

		bob.signForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Form badForm("BadForm", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "\nError creating form: " << e.what() << std::endl;
	}

	return (0);
}
