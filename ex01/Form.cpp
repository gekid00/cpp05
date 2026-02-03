#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _gradeToSign(signGrade), _gradeToExec(executeGrade), _signed(false)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form& toCopy)
	: _name(toCopy._name), _gradeToSign(toCopy._gradeToSign),
	  _gradeToExec(toCopy._gradeToExec), _signed(toCopy._signed)
{
}

Form& Form::operator=(const Form& toAssign)
{
	if (this != &toAssign)
		_signed = toAssign._signed;
	return *this;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream& operator<<(std::ostream& pid, const Form& form)
{
	pid << "Form \"" << form.getName() << "\", Sign grade: " << form.getGradeToSign()
		<< ", Execute grade: " << form.getGradeToExec()
		<< ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return pid;
}
