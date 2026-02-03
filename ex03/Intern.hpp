#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& toCopy);
		Intern& operator=(const Intern& toAssign);
		AForm* makeForm(const std::string &formName, const std::string &target) const;
	private:
		AForm* createShrubbery(const std::string &target) const;
		AForm* createRobotomy(const std::string &target) const;
		AForm* createPresidential(const std::string &target) const;
};

#endif
