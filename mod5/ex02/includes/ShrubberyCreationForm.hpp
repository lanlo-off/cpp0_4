#ifndef SCHRUBBERYFORM_HPP
#define SCHRUBBERYFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& model);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

	std::string const& getTarget() const;
	virtual void	execute(Bureaucrat const& executor) const;

class NoOutfileAccessException : public std::exception
{
	public:
		const char* what() const throw();
};
};

#endif