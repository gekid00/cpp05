#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	public:
		Form(const std::string& name, int signGrade, int executeGrade);
		~Form();
		Form(const Form& toCopy);
		Form& operator=(const Form& toAssign);
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
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _signed;
};

std::ostream& operator<<(std::ostream& pid, const Form& form);

#endif
