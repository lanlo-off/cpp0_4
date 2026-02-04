#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("no wrong type :(") {}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {}

WrongAnimal::WrongAnimal(WrongAnimal const& model) : _type(model._type) {}

WrongAnimal::~WrongAnimal(void) {}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs)
{
	_type = rhs._type;
	return (*this);
}

std::string	WrongAnimal::getType(void)
{
	return (_type);
}

void	WrongAnimal::makeSound(void)
{
	// std::cout << "The animal of type " << this->_type << " makes " << sound << "!\n";
	std::string sound;
	if (_type == "Cat")
		sound = "Ouaf";
	else if (_type == "Dog")
		sound = "Meow";
	else
		sound = "no sound for this type of WrongAnimal";
std::cout << sound << std::endl;
}

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {}

WrongCat::WrongCat(WrongCat const& model) : WrongAnimal(model) {}

WrongCat::~WrongCat(void) {}

WrongCat& WrongCat::operator=(WrongCat const& rhs)
{
	WrongAnimal::operator=(rhs);
	return (*this);
}