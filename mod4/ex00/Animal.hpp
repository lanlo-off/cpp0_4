#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
public:
	Animal(void);
	Animal(std::string type);
	Animal(Animal const& model);
	~Animal(void);

	Animal& operator=(Animal const& rhs);

	void	makeSound(void) const;
	std::string	getType(void) const;

protected:
	std::string _type;
};

#endif