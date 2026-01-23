#include "HumanB.hpp"

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
} 

HumanB::HumanB(std::string name) : _name(name), _weapon("no weapon")
{
	return ;
}

HumanB::HumanB(void) : _name("default name"), _weapon("no weapon")
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}