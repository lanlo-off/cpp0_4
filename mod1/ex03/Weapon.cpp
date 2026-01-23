#include "Weapon.hpp"

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
} 

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
} 

Weapon::Weapon(std::string wType) : _type(wType)
{
	return ;
}

Weapon::Weapon(void) : _type("default weapon")
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}