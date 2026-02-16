#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Grade too high\n");
		}
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Grade too low\n");
		}
};

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
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);

#endif