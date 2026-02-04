#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat const& model);
	~Cat(void);

	Cat& operator=(Cat const& rhs);

	// void	makeSound(std::string sound);

};

#endif