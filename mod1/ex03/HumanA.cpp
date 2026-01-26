#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
} 

HumanA::HumanA(std::string name, Weapon& wType) : _name(name), _weapon(wType)
{
	return ;
}

HumanA::HumanA(void) : _name("default name"), _weapon(*(new Weapon("default sword")))
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}