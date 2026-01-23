#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "ADDRESSES :" << std::endl << "Address of the string : " << &str << std::endl;
	std::cout << "Address of the pointer : " << stringPTR << std::endl;
	std::cout << "Address of the reference : " << &stringREF << std::endl << std::endl;

	std::cout << "VALUES :" << std::endl << "Value of the string : " << str << std::endl;
	std::cout << "Value pointed to by the pointer : " << *stringPTR << std::endl;
	std::cout << "Value pointed to by the reference : " << stringREF << std::endl;

	return (0) ;
}