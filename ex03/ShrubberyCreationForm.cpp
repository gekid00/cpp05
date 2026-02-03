#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy)
	: AForm(toCopy), _target(toCopy._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toAssign)
{
	if (this != &toAssign)
	{
		AForm::operator=(toAssign);
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "    *" << std::endl;
	file << "   ***" << std::endl;
	file << "  *****" << std::endl;
	file << " *******" << std::endl;
	file << "*********" << std::endl;
	file << "   |||" << std::endl;
	file.close();
}
