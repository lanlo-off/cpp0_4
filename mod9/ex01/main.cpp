/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:14:06 by cpollock          #+#    #+#             */
/*   Updated: 2026/01/27 16:14:19 by cpollock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int arg_c, char *arg_s[])
{
	if (arg_c != 2) {
		std::cerr << "\e[3m" "Error: ";
		if (arg_c < 2)
			std::cerr << "Not enough arguments";
		else
			std::cerr << "Too many arguments";
		std::cerr << ": expected \"./RPN expression\"." "\e[0m" << '\n';
		return (1);
	}
	try {
		RPN	RPNcalculator;
		std::cout << RPNcalculator.rpnOperate(arg_s[1]) << '\n';
	}
	catch (std::exception &e) {
		std::cerr << "\e[0m" "\e[3m" "Error: " << e.what() << "\e[0m" << '\n';
		return (1);
	}
	return (0);
}
