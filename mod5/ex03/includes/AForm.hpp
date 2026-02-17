#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool	_signed;
	const int	_gReqSign;
	const int	_gReqExec;

public:
	AForm();
	AForm(std::string name, int gSign, int gExec);
	AForm(AForm const& model);
	virtual ~AForm();

	AForm& operator=(AForm const& rhs);

	std::string const& getName() const;
	bool const& getSigned() const;
	int const& getGReqSign() const;
	int const& getGReqExec() const;

	void	beSigned(Bureaucrat const& bureaucrat);
	void	checkRequirements(Bureaucrat const& bureaucrat) const;
	virtual void	execute(Bureaucrat const& executor) const = 0;

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

class FormNotSignedException : public std::exception
{
	public:
		const char* what() const throw();
};
};

std::ostream& operator<<(std::ostream& o, AForm const& rhs);

#endif
