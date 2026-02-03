#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& toCopy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& toAssign);
		void execute(const Bureaucrat& executor) const;
	private:
		const std::string _target;
};

#endif
