/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:42:57 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/11 11:10:18 by ldubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "ansi.hpp"
#include "BitcoinExchange.hpp"

void printException(const std::exception& e)
{
	std::cerr << ANSI_BOLD << ANSI_FG_RED << "Exception: " << ANSI_RESET
			  << ANSI_FG_RED << e.what() << ANSI_RESET << "\n";
}

int main(int argc, char** argv)
{
	BitcoinExchange	  exchange;
	const std::string database = "data.csv";

	if (argc != 2)
	{
		std::cerr << "usage: ./btc <file>\n";
		return EXIT_FAILURE;
	}
	try
	{
		exchange.loadRates(database);
		exchange.loadAccount(argv[1]);
	}
	catch (const std::exception& e)
	{
		printException(e);
		return EXIT_FAILURE;
	}
	std::cout << exchange;
	return EXIT_SUCCESS;
}
