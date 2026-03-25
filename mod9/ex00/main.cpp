/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:54:02 by cpollock          #+#    #+#             */
/*   Updated: 2026/01/23 10:54:12 by cpollock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int arg_c, char *arg_s[])
{
	if (arg_c != 2) {
		std::cerr << "\e[3m" "Error: ";
		if (arg_c < 2)
			std::cerr << "Not enough arguments";
		else
			std::cerr << "Too many arguments";
		std::cerr << ": expected \"./btc file_name\"." "\e[0m" << '\n';
		return (1);
	}
	try {
		BitcoinExchange	changer;
		changer.loadDatabase("data.csv");
		changer.readInput(arg_s[1]);
	}
	catch (std::exception &e) {
		std::cerr << "\e[0m" "\e[3m" "Error: " << e.what() << "\e[0m" << '\n';
		return (1);
	}
	return (0);
}
