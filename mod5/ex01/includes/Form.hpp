#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool	_signed;
	const int	_gReqSign;
	const int	_gReqExec;

public:
	Form();
	Form(std::string name, int gSign, int gExec);
	Form(Form const& model);
	~Form();

	Form& operator=(Form const& rhs);

	std::string const& getName() const;
	bool const& getSigned() const;
	int const& getGReqSign() const;
	int const& getGReqExec() const;

	void	beSigned(Bureaucrat const& bureaucrat);

	class GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw();
};
};

std::ostream& operator<<(std::ostream& o, Form const& rhs);

#endif
