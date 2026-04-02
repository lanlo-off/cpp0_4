/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:46:15 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/31 13:37:28 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include <deque>

#include "ansi.hpp"
#include "PmergeMe.hpp"

void printException(const std::exception& e)
{
	std::cerr << ANSI_BOLD << ANSI_FG_RED << "Exception: " << ANSI_RESET
			  << ANSI_FG_RED << e.what() << ANSI_RESET << "\n";
}

int main(int argc, char** argv)
{

	std::srand(static_cast<unsigned int>(std::clock()));

	if (argc < 2)
	{
		std::cerr << "usage: ./PmergeMe <sequence>\n";
		return EXIT_FAILURE;
	}
	try
	{
		std::vector<unsigned int> sequence
				= (argc > 2
						   ? PmergeMe<std::vector, unsigned int>::parseSequence(
									 &argv[1],
									 static_cast<std::size_t>(argc - 1))
						   : PmergeMe<std::vector, unsigned int>::parseSequence(
									 argv[1]));
		std::cout << std::left << std::setw(10) << "Before:" << sequence
				  << "\n";
		PmergeMe<std::vector, unsigned int>::sortSequence(sequence);
		std::cout << std::left << std::setw(10) << "After:" << sequence << "\n";
		PmergeMe<std::vector, unsigned int>::benchSort(sequence.size());
		PmergeMe<std::deque, unsigned int>::benchSort(sequence.size());
	}
	catch (const std::exception& e)
	{
		printException(e);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
