#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& toCopy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& toAssign);
		void execute(const Bureaucrat& executor) const;
	private:
		const std::string _target;
};

#endif