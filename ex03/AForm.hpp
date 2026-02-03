#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string& name, int signGrade, int executeGrade);
		virtual ~AForm();
		AForm(const AForm& toCopy);
		AForm& operator=(const AForm& toAssign);
		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat& bureaucrat);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		virtual void execute(const Bureaucrat& executor) const = 0;
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _signed;
};

std::ostream& operator<<(std::ostream& pid, const AForm& form);

#endif