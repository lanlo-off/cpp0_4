/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:23:57 by cpollock          #+#    #+#             */
/*   Updated: 2026/01/28 13:24:09 by cpollock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int arg_c, char *arg_s[])
{
	if (arg_c <= 1) {
		std::cerr << "\e[3m" "Error: No arguments." "\e[0m" << '\n';
		return (1);
	}
	try {
		PmergeMe	sorter;
		for (int i = 1; i < arg_c; i++)
			sorter.push_to_cont(arg_s[i]);
		
		std::cout << "Unsorted:  ";
		sorter.display_vector();

		clock_t	startVec = clock();
		sorter.sortVector();
		clock_t	endVec = clock();
		double	timeVec = static_cast<double>(endVec - startVec) / (CLOCKS_PER_SEC / 1000000.0);

		clock_t	startDeq = clock();
		sorter.sortDeque();
		clock_t	endDeq = clock();
		double	timeDeq = static_cast<double>(endDeq - startDeq) / (CLOCKS_PER_SEC / 1000000.0);

		std::cout << "Sorted:    ";
		sorter.display_vector();

		std::cout << "Time to process a range of " << arg_c - 1
		<< " elements with std::vector : " << timeVec << " μs" << '\n';
		std::cout << "Time to process a range of " << arg_c - 1
		<< " elements with std::deque  : " << timeDeq << " μs" << '\n';

		sorter.sortCheckVector();
		sorter.sortCheckDeque();
	}
	catch (std::exception &e) {
		std::cerr << "\e[0m" "\e[3m" "Error: " << e.what() << "\e[0m" << '\n';
		return (1);
	}
	return (0);
}
