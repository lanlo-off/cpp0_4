#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default target") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& model) : AForm(model), _target(model._target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
		this->AForm::operator=(rhs); 
	}
	return (*this);
}

std::string const& PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	this->checkRequirements(executor);
	std::cout	<< this->getTarget()
				<< " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
}