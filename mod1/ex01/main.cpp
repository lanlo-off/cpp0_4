#include "Zombie.hpp"

int	main(void)
{
	int	nbZ = 3;
	
	Zombie	*horde = zombieHorde(nbZ, "lanlo");
	for (int i = 0; i < nbZ; i++)
	{
		std::cout << "Zombie [" << i << "] -> ";
		horde[i].announce();
	}
	delete [] horde;
	return (0) ;
}