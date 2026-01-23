#include "HumanB.hpp"

int	main(void)
{
	Weapon club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");//fonctionne pas -> ref / pointeur ? Alloc ?
	bob.attack();
	return (0) ;
}