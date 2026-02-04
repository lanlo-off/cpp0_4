#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const& model);
	~WrongAnimal(void);

	WrongAnimal& operator=(WrongAnimal const& rhs);

	void	makeSound(void);
	std::string	getType(void);

protected:
	std::string _type;
};

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const& model);
	~WrongCat(void);

	WrongCat& operator=(WrongCat const& rhs);
};

#endif