#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy)
	: AForm(toCopy), _target(toCopy._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& toAssign)
{
	if (this != &toAssign)
	{
		AForm::operator=(toAssign);
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout << "Drrrr... Whirrrr..." << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}
