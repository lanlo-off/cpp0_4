#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const& model);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const& rhs);
	Bureaucrat& operator++();
	Bureaucrat& operator--();

	std::string const& getName() const;
	int const& getGrade() const;
	void	signForm(Form& form) const;


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

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);

#endif