#include "../includes/easyfind.hpp"
#include <iostream>
#include <vector>

int main(int argc, char **argv) {

	if (argc > 2) {
		std::vector<int> tab;
		int target = atoi(argv[argc - 1]);
		
		for (int i = 1; i < argc - 1; i++) {
			tab.push_back(atoi(argv[i]));
		}

		try {
			std::vector<int>::iterator it = easyfind(tab, target);
			std::cout << "number " << *it << " found !" << std::endl;
		}
		catch (const std::exception &e) {
			std::cout << target << " : " << e.what() << std::endl;
		}
	}
	return 0;
}