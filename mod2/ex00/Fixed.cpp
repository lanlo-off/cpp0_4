#include "Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(Fixed const & model)
{
	std::cout << "Copy constructor called\n";
	this->operator=(model);
	return ;
}

Fixed &Fixed::operator=(Fixed const &base)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &base)
		std::cout << "Copy assignment operator called on himself\n";
	else
		this->_value = base.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called\n";
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}