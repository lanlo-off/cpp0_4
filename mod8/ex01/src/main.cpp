#include "../includes/Span.hpp"
#include <ctime>

int main() {
	try {
		std::vector<int> vec;
		Span sp(10000);
		std::srand(std::time(NULL));

		for (int i = 0; i < 10000; ++i) {
		    vec.push_back(rand());
		}
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		try {
			sp.addNumber(14);//Pour prouver qu'on peut pas rajouter un int de plus
		}
		catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	{
		std::cout << "Test subject : " << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}