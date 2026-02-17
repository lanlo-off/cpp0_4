#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
public:
	Intern();
	Intern(Intern const& model);
	~Intern();

	Intern& operator=(Intern const& rhs);

	AForm*	makeForm(std::string const& name, std::string const& target);
	AForm*	makeRobotomy(std::string const& target);
	AForm*	makeShrubbery(std::string const& target);
	AForm*	makePresidential(std::string const& target);

	class FormUnknownException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};


#endif