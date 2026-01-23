#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*newZ = new Zombie(name);
	
	return (newZ);
}

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
