#ifndef HUMANA_H
# define HUMANA_H
# include "Weapon.hpp"

class HumanA{
private:
	std::string _name;
	Weapon& _weapon;

public:
	HumanA(void);
	HumanA(std::string name, Weapon& wType);
	~HumanA(void);

	void	attack(void);
};

#endif