#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& toCopy);
		Bureaucrat& operator=(const Bureaucrat& toAssign);
		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form) const;
		void executeForm(const AForm &form) const;
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
		int _grade;
};

std::ostream& operator<<(std::ostream& pid, const Bureaucrat& bureaucrat);

#endif
