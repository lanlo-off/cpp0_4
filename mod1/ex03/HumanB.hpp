#ifndef HUMANB_H
# define HUMANB_H

#include "HumanA.hpp"

class HumanB{
private:
	std::string _name;
	Weapon *_weapon;

public:
	HumanB(void);
	HumanB(std::string name);
	~HumanB(void);

	void	attack(void);
	void	setWeapon(Weapon& weapon);
};

#endif