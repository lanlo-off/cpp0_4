#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default name"), _hp(10), _nrj(10), _ad(0) 
{
	std::cout << "Default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _nrj(10), _ad(0) 
{
	std::cout << "Constructor with name called for " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& model) : _name(model._name), _hp(model._hp), _nrj(model._nrj), _ad(model._ad) 
{
	std::cout << "Copy constructor called with target " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called on " << _name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_nrj == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack " << target << "because he has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << "attacks " << target << ", causing " << _ad << "points of damage!" << std::endl;
	_nrj--;//ou --nrj ?
}
void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_nrj == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair himself because he has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << "repairs himself for " << amount << "hps!" << std::endl;
	_nrj--;//ou --nrj ?
}