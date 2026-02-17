#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default target") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) :  AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& model) : AForm(model), _target(model._target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
		this->AForm::operator=(rhs); 
	}
	return (*this);
}

std::string const& RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	this->checkRequirements(executor);
	std::cout	<< "*ZZZZZ BRRRR TRRRRRR*\n";
	if (std::rand() % 2)
	{
		std::cout	<< this->getTarget()
					<< " has been robotomized."
					<< std::endl;
	}
	else
	{
		std::cout	<< "Robotomy on "
					<< this->getTarget()
					<< " failed dramatically."
					<< std::endl;
	}
}