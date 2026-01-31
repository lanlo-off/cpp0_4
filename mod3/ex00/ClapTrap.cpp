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

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
{
	_name = rhs._name;
	_hp = rhs._hp;
	_nrj = rhs._nrj;
	_ad = rhs._ad;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack " << target << "because he has no hp left!" << std::endl;
		return ;
	}
	if (_nrj == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack " << target << "because he has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << "attacks " << target << ", causing " << _ad << "points of damage!" << std::endl;
	--_nrj;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	int damage = (amount <= _hp ? amount : _hp);//pour pas prendre plus que ce que tu n'as

	_hp -= damage;
	std::cout << "ClapTrap " << _name << "takes" << damage << " damage, getting him to " << _hp << "hp!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair himself because he has no hp left!" << std::endl;
		return ;
	}
	if (_nrj == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair himself because he has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << "repairs himself for " << amount << "hps!" << std::endl;
	--_nrj;
}