#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Carine Camby"), _grade(75) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
	if (_grade < 1)
	{
		_grade = 1;
		throw GradeTooHighException();
	}
	if (_grade > 150)
	{
		_grade = 150;
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const& model) : _name(model._name), _grade(model._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
	_grade = rhs._grade;
	return (*this);
}

Bureaucrat& Bureaucrat::operator++()
{
	if (_grade > 1)
		--_grade;
	else
		throw GradeTooHighException();
	return (*this);
}

Bureaucrat& Bureaucrat::operator--()
{
	if (_grade < 150)
		++_grade;
	else
		throw GradeTooLowException();
	return (*this);
}

std::string const& Bureaucrat::getName() const
{
	return (_name);
}
int const& Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName()
				<< " signed "
				<< form.getName()
				<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName()
				<< " couldn't sign "
				<< form.getName()
				<< " because "
				<< e.what()
				<< std::endl;
	}
	
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs)
{
	o << rhs.getName()
		<< ", bureaucrat grade "
		<< rhs.getGrade()
		<< "."
		<< std::endl;
	return (o);
}