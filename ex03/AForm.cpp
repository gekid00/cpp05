#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _gradeToSign(signGrade), _gradeToExec(executeGrade), _signed(false)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& toCopy)
	: _name(toCopy._name), _gradeToSign(toCopy._gradeToSign),
	  _gradeToExec(toCopy._gradeToExec), _signed(toCopy._signed)
{
}

AForm& AForm::operator=(const AForm& toAssign)
{
	if (this != &toAssign)
		_signed = toAssign._signed;
	return *this;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed";
}

std::ostream& operator<<(std::ostream& pid, const AForm& AForm)
{
	pid << "AForm \"" << AForm.getName() << "\", Sign grade: " << AForm.getGradeToSign()
		<< ", Execute grade: " << AForm.getGradeToExec()
		<< ", Signed: " << (AForm.isSigned() ? "Yes" : "No");
	return pid;
}