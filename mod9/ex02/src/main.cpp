#include "../includes/PmergeMe.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac <= 1) {
		std::cerr << "Error: No arguments." << '\n';
		return (1);
	}
	try {
		PmergeMe	sorter;
		for (int i = 1; i < ac; i++)
			sorter.push_to_cont(av[i]);
		
		std::cout << "Unsorted: ";
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

		std::cout 	<< "Time to process a range of " 
					<< ac - 1 << " elements with std::vector : " 
					<< timeVec << " μs" << '\n';
		std::cout	<< "Time to process a range of "
					<< ac - 1 << " elements with std::deque : "
					<< timeDeq << " μs" << '\n';

		sorter.sortCheckVector();
		sorter.sortCheckDeque();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
