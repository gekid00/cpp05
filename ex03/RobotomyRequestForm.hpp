#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& toCopy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& toAssign);
		void execute(const Bureaucrat& executor) const;
	private:
		const std::string _target;
};

#endif
