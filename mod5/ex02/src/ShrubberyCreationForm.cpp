#include "../includes/ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 147, 137), _target("default target") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 147, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& model) : AForm(model), _target(model._target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
		this->AForm::operator=(rhs); 
	}
	return (*this);
}

std::string const& ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	this->checkRequirements(executor);
	std::string filename = _target;
	std::ofstream outfile(filename.append("_shrubbery").c_str());
	if (!outfile)
		throw NoOutfileAccessException();
	outfile << "       _-_\n"
			"    /`       `\\\n"
			"   /     _-\"\"\"\"\"-\\\n"
			"  /     /         \\\n"
			" /     /           \\\n"
			"/_____/_____________\\\n"
			"      ||     ||\n"
			"      ||     ||\n"
			"      ||     ||\n";
}

const char* ShrubberyCreationForm::NoOutfileAccessException::what() const throw()
{
	return ("Can not access outfile\n");
}