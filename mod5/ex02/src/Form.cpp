#include "../includes/Form.hpp"

Form::Form() : _name("Default form"), _signed(false), _gReqSign(75), _gReqExec(75) {}

Form::Form(std::string name, int gSign, int gExec) : _name(name), _signed(false), _gReqSign(gSign), _gReqExec(gExec)
{
	if (_gReqExec < 1 || _gReqSign < 1)
		throw GradeTooHighException();
	if (_gReqExec > 150 || _gReqSign > 150)
		throw GradeTooLowException();
}

Form::Form(Form const& model) : _name(model._name), _signed(model._signed), _gReqSign(model._gReqSign), _gReqExec(model._gReqExec)
{
	if (_gReqExec < 1 || _gReqSign < 1)
		throw GradeTooHighException();
	if (_gReqExec > 150 || _gReqSign > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form& Form::operator=(Form const& rhs)
{
	_signed = rhs._signed;
	return (*this);
}

std::string const& Form::getName() const
{
	return (_name);
}

bool const& Form::getSigned() const
{
	return (_signed);
}

int const& Form::getGReqSign() const
{
	return (_gReqSign);
}

int const& Form::getGReqExec() const
{
	return (_gReqExec);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	// if (_signed)
	// 	std::cout << "Form already signed"
	// 				<< std::endl;
	if (bureaucrat.getGrade() > _gReqSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& o, Form const& rhs)
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