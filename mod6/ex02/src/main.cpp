#include "../includes/Base.hpp"
/**
 * @brief 
 * @return int 
 */
int main()
{
	std::srand(std::time(NULL));
	
	Base* p = generate();

	identify(p);
	identify(*p);

	delete p;
	return 0;
}