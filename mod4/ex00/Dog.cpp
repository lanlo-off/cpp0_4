#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {}

Dog::Dog(Dog const& model) : Animal(model) {}

Dog::~Dog(void) {}

Dog& Dog::operator=(Dog const& rhs)
{
	Animal::operator=(rhs);
	return (*this);
}
