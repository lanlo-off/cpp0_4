#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "=== Valid bureaucrat and increments ===" << std::endl;
	try {
		Bureaucrat a("Jean", 2);
		std::cout << a;
		++a; // passe à 1
		std::cout << "after ++: " << a;
		++a; // doit lancer GradeTooHighException
		std::cout << a;
	} catch (std::exception &e) {
		std::cerr << e.what();
	}

	std::cout << "\n=== Valid bureaucrat and decrements ===" << std::endl;
	try {
		Bureaucrat b("Marie", 149);
		std::cout << b;
		--b; // passe à 150
		std::cout << "after --: " << b;
		--b; // doit lancer GradeTooLowException
		std::cout << b;
	} catch (std::exception &e) {
		std::cerr << e.what();
	}

	std::cout << "\n=== Construct with too high grade ===" << std::endl;
	try {
		Bureaucrat c("TooHigh", 0);
		std::cout << c;
	} catch (std::exception &e) {
		std::cerr << e.what();
	}

	std::cout << "\n=== Construct with too low grade ===" << std::endl;
	try {
		Bureaucrat d("TooLow", 151);
		std::cout << d;
	} catch (std::exception &e) {
		std::cerr << e.what();
	}

	return (0);
}