#include "../includes/BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "\e[3m" "Error: ";
		if (ac < 2)
			std::cerr << "Not enough arguments";
		else
			std::cerr << "Too many arguments";
		std::cerr << ": expected \"./btc file_name\"." "\e[0m" << '\n';
		return (1);
	}
	try {
		BitcoinExchange	changer;
		changer.loadDatabase("data.csv");
		changer.readInput(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << "\e[0m" "\e[3m" "Error: " << e.what() << "\e[0m" << '\n';
		return (1);
	}
	return (0);
}
