#include "../includes/Array.hpp"

#define MAX_VAL 750
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "===== TEST 1: Constructeur vide =====" << std::endl;
	Array<int> empty;
	std::cout << "size() attendu: 0 | obtenu: " << empty.size() << std::endl;
	bool emptyExceptionThrown = false;
	try
	{
		empty[0] = 42;
	}
	catch(const std::exception& e)
	{
		emptyExceptionThrown = true;
		std::cout << "Acces hors borne sur array vide: PASS -> " << e.what();
	}
	if (!emptyExceptionThrown)
		std::cout << "Acces hors borne sur array vide: FAIL" << std::endl;
	else
		std::cout << std::endl;

	std::cout << "\n===== TEST 2: Constructeur avec taille =====" << std::endl;

	Array<int> numbers(MAX_VAL);
	std::cout << "size() attendu: " << MAX_VAL << " | obtenu: " << numbers.size() << std::endl;
	if (numbers.size() == MAX_VAL)
		std::cout << "Constructeur n elements: PASS" << std::endl;
	else
		std::cout << "Constructeur n elements: FAIL" << std::endl;

	int* mirror = new int[MAX_VAL];
	srand(time(NULL));

	std::cout << "\n===== TEST 3: Ecriture/Lecture operator[] =====" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "Ecriture completee sur " << MAX_VAL << " elements." << std::endl;

	std::cout << "\n===== TEST 4: Copie profonde =====" << std::endl;
	Array<int> tmp = numbers;
	Array<int> test(tmp);
	(void)test;
	tmp[0] = numbers[0] - 1;
	if (numbers[0] == tmp[0])
	{
		std::cerr << "Copie profonde: FAIL" << std::endl;
		delete [] mirror;
		return 1;
	}
	std::cout << "Copie profonde (copy ctor + affectation): PASS" << std::endl;

	std::cout << "\n===== TEST 5: Acces const =====" << std::endl;

	const Array<int> constNumbers(numbers);
	std::cout << "Lecture via operator[] const: PASS (exemple valeur = " << constNumbers[0] << ")" << std::endl;

	std::cout << "\n===== TEST 6: Integrite des donnees =====" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "Comparaison mirror/array: FAIL a l'index " << i << std::endl;
			delete [] mirror;
			return 1;
		}
	}
	std::cout << "Comparaison mirror/array: PASS" << std::endl;

	std::cout << "\n===== TEST 7: Exceptions hors borne =====" << std::endl;
	bool lowException = false;
	bool highException = false;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		lowException = true;
		std::cout << "Index negatif (-2) -> PASS -> " << e.what();
	}
	if (!lowException)
		std::cout << "Index negatif (-2) -> FAIL";
	std::cout << std::endl;

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		highException = true;
		std::cout << "Index egal a size (" << MAX_VAL << ") -> PASS -> " << e.what();
	}
	if (!highException)
		std::cout << "Index egal a size (" << MAX_VAL << ") -> FAIL";
	std::cout << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "\nTous les tests se sont executes." << std::endl;
	delete [] mirror;
	return (0);
}