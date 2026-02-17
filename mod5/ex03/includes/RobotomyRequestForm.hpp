#ifndef ROBOTOMYFORM_HPP
#define ROBOTOMYFORM_HPP

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& model);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

	std::string const& getTarget() const;
	void	execute(Bureaucrat const& executor) const;
};

#endif