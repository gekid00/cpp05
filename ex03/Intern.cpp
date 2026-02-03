#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& toCopy)
{
	(void)toCopy;
}

Intern& Intern::operator=(const Intern& toAssign)
{
	(void)toAssign;
	return *this;
}

AForm* Intern::createShrubbery(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	typedef AForm* (Intern::*formCreator)(const std::string &) const;
	
	struct FormInfo
	{
		std::string name;
		formCreator creator;
	};
	
	FormInfo forms[3] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*forms[i].creator)(target);
		}
	}
	
	std::cout << "Error: Unknown form type '" << formName << "'" << std::endl;
	return NULL;
}
