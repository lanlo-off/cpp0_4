#include "Animal.hpp"

Animal::Animal(void) : _type("no type :(") {}

Animal::Animal(std::string type) : _type(type) {}

Animal::Animal(Animal const& model) : _type(model._type) {}

Animal::~Animal(void) {}

Animal& Animal::operator=(Animal const& rhs)
{
	_type = rhs._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	// std::cout << "The animal of type " << this->_type << " makes " << sound << "!\n";
	std::string sound;
	if (_type == "Dog")
		sound = "Ouaf";
	else if (_type == "Cat")
		sound = "Meow";
	else
		sound = "no sound for this type of Animal";
std::cout << sound << std::endl;
}
