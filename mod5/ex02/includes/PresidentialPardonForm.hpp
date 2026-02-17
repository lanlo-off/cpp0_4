#ifndef PRESIDENTIALFORM_HPP
#define PRESIDENTIALFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& model);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

	std::string const& getTarget() const;
	void	execute(Bureaucrat const& executor) const;
};

#endif