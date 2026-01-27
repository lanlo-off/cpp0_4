#include "harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "./harlFilter 'level' to launch the program" << std::endl;
		return (1);
	}
	std::string	filter = av[1];
	Harl	harl;

	harl.complain(filter);
	return (0);
}
