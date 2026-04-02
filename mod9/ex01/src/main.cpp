#include "../includes/RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: ";
		if (ac < 2)
			std::cerr << "Not enough arguments";
		else
			std::cerr << "Too many arguments";
		std::cerr << ": expected \"./RPN expression\"." << '\n';
		return (1);
	}
	try {
		RPN	RPNcalculator;
		std::cout << RPNcalculator.RPNOperate(av[1]) << '\n';
	}
	catch (std::exception &e) {
		std::cerr <<  "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}
