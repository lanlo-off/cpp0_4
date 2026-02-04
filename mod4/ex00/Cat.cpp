#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {}

Cat::Cat(Cat const& model) : Animal(model) {}

Cat::~Cat(void) {}

Cat& Cat::operator=(Cat const& rhs)
{
	Animal::operator=(rhs);
	return (*this);
}
