#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zHeap = new Zombie("zHeap");
	zHeap->announce();
	randomChump("zStack");
	delete(zHeap);
	return (0) ;
}