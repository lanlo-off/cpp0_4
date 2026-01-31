#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
private:
	std::string _name;
	int			_hp;
	int			_nrj;
	int			_ad;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& model);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap& operator=(ClapTrap const& rhs);
};



#endif