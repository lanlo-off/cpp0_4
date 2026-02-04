#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const& model);
	~Dog(void);

	Dog& operator=(Dog const& rhs);

	// void	makeSound(std::string sound);

};

#endif