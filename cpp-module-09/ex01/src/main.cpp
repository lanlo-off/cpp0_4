/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:44:49 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/12 15:46:06 by ldubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "ansi.hpp"
#include "RPN.hpp"

void printException(const std::exception& e)
{
	std::cerr << ANSI_BOLD << ANSI_FG_RED << "Exception: " << ANSI_RESET
			  << ANSI_FG_RED << e.what() << ANSI_RESET << "\n";
}

int main(int argc, char** argv)
{
	int result;

	if (argc != 2)
	{
		std::cerr << "usage: ./RPN <expression>\n";
		return EXIT_FAILURE;
	}
	try
	{
		result = RPN::evaluate(argv[1]);
	}
	catch (const std::exception& e)
	{
		printException(e);
		return EXIT_FAILURE;
	}
	std::cout << result << "\n";
	return EXIT_SUCCESS;
}
