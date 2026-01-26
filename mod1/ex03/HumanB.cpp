#include "HumanB.hpp"

void	HumanB::attack(void)
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	return ;
}

HumanB::HumanB(void) : _name("default name"), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}