#include "../includes/iter.hpp"

int main()
{
	std::cout << "===== TEST INT =====\n";
	int intArray[] = {1, 42, -5, 10};
	size_t intSize = sizeof(intArray) / sizeof(int);

	iter(intArray, intSize, printElement);
	std::cout << "\n";

	iter(intArray, intSize, printElement<int>);//Possible de rajouter <int> apres printElement pour preciser qu'on force la version de printElement sur les int dans ce cas
	std::cout << "\n";

	iter(intArray, intSize, compareWith42);
	std::cout << "\n";

	iter(intArray, intSize, greaterThanZero);
	std::cout << "\n\n";


	std::cout << "===== TEST DOUBLE =====\n";
	double doubleArray[] = {0.5, 42.0, -1.1};
	size_t doubleSize = sizeof(doubleArray) / sizeof(double);

	iter(doubleArray, doubleSize, printElement);
	std::cout << "\n";

	iter(doubleArray, doubleSize, compareWith42);
	std::cout << "\n";

	iter(doubleArray, doubleSize, greaterThanZero);
	std::cout << "\n" << "\n";


	std::cout << "===== TEST STRING =====\n";
	std::string strArray[] = {"hello", "world"};
	size_t strSize = sizeof(strArray) / sizeof(std::string);

	iter(strArray, strSize, printElement);
	std::cout << "\n" << std::endl;

	/*les autres fonctions ne compilent pas avec les strings a cause du static_cast<string>(42) dedans qui n'existe pas*/

	std::cout << "===== TEST CONST T& (1re surcharge) =====\n";
	int tab1[] = {10, 20, 30};
	iter(tab1, 3, printElement<int>);  // Prend const T&, donc 1re surcharge
	std::cout << "\n\n";

	std::cout << "===== TEST NON-CONST T& (2e surcharge) =====\n";
	int tab2[] = {10, 20, 30};
	iter(tab2, 3, printNonConstRef<int>);  // Prend T& mutable, donc 2e surcharge
	std::cout << "\nApres increment: ";
	iter(tab2, 3, printElement<int>);
	std::cout << "\n";

	return (0);
}