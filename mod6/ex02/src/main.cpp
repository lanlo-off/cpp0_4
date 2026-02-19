#include "../includes/Base.hpp"
/**
 * @brief 
 * @return int 
 */
int main()
{
	std::srand(std::time(NULL));//genere une "seed" de rand par ms car rand sinon renvoie la meme suite a chaque fois
	
	Base* p = generate(); // On génère aléatoirement A, B ou C

	identify(p);
	identify(*p);

	delete p;
	return 0;
}