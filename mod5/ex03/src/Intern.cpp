#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

static std::string _knownForms[3] = {"Shrubbery form", "Robotomy form", "Presidential form"};

static AForm *(Intern::*_functionPtr[3])( const std::string &) =	{&Intern::makeShrubbery,
																	&Intern::makeRobotomy, 
																	&Intern::makePresidential};


Intern::Intern() {}

Intern::Intern(Intern const& model) {(void)model;}

Intern::~Intern() {}

Intern& Intern::operator=(Intern const& rhs)
{
	(void)rhs;
	return (*this);
}

AForm*	Intern::makeForm(std::string const& name, std::string const& target)
{
	for (int i = 0; i < 4; i++)
	{
		if (name == _knownForms[i])
		{
			std::cout	<< "Intern creates "
						<< _knownForms[i]
						<< std::endl;
			return ((this->*_functionPtr[i])(target));
		}
	}
	throw FormUnknownException();
}

AForm	*Intern::makeShrubbery(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomy(std::string const& target )
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidential(std::string const& target )
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::FormUnknownException::what() const throw()
{
	return ("Form's name not recognised\n");
}