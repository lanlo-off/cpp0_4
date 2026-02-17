#include "../includes/AForm.hpp"

AForm::AForm() : _name("Default form"), _signed(false), _gReqSign(75), _gReqExec(75) {}

AForm::AForm(std::string name, int gSign, int gExec) : _name(name), _signed(false), _gReqSign(gSign), _gReqExec(gExec)
{
	if (_gReqExec < 1 || _gReqSign < 1)
		throw GradeTooHighException();
	if (_gReqExec > 150 || _gReqSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& model) : _name(model._name), _signed(model._signed), _gReqSign(model._gReqSign), _gReqExec(model._gReqExec)
{
	if (_gReqExec < 1 || _gReqSign < 1)
		throw GradeTooHighException();
	if (_gReqExec > 150 || _gReqSign > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm& AForm::operator=(AForm const& rhs)
{
	_signed = rhs._signed;
	return (*this);
}

std::string const& AForm::getName() const
{
	return (_name);
}

bool const& AForm::getSigned() const
{
	return (_signed);
}

int const& AForm::getGReqSign() const
{
	return (_gReqSign);
}

int const& AForm::getGReqExec() const
{
	return (_gReqExec);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed\n");
}

void	AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _gReqSign)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::checkRequirements(Bureaucrat const& bureaucrat) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (_gReqExec < bureaucrat.getGrade())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o, AForm const& rhs)
{
	o << "Form "
		<< rhs.getName()
		<< ", requires a minimum of grade "
		<< rhs.getGReqSign()
		<< " to be signed.\nAnd a minimum of grade "
		<< rhs.getGReqExec()
		<< " to be executed.\nIt is currently"
		<< (rhs.getSigned() ? "" : " not")
		<< " signed."
		<< std::endl;
	return (o);
}