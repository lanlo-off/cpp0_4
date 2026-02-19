#include "../includes/Base.hpp"

Base* generate()
{
	int random = std::rand() % 3;
	
	switch (random)
	{
	case 0:
		std::cout << "Generated class A" << std::endl;
		return (new A);
	case 1:
		std::cout << "Generated class B" << std::endl;
		return (new B);
	case 2:
		std::cout << "Generated class C" << std::endl;
		return (new C);
	default:
		std::cout << "Rupture de l'espace temps" << std::endl;
		return (NULL);
	}
}

/**
 * @brief dynamic cast sur un pointeur
 * Si echoue -> renvoie NULL
 * Donc beaucoup plus simple a tester
 * 
 * @param p 
 */
void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Rupture de l'espace temps" << std::endl;

}

/**
 * @brief dynamic cast sur une reference
 * si echoue --> Renvoie une exception car une reference ne peut etre NULL !!!!
 * Donc on fait des try qui ne vont au bout que si pas d'exception qui sort !
 * 
 * @param p 
 */
void	identify(Base& p)
{
	/*Tentative pour vois si c'est A*/
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;//Pour éviter le warning "unused variable"
		std::cout << "A" << std::endl;//Si on arrive jusqu'ici c'est que le cast n'a pas throw d'exception !
		return;
	}
	catch (const std::exception& e) {}

	/*Tentative pour vois si c'est B*/
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception& e) {}

	/*Tentative pour vois si c'est C*/
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception& e) {}
}